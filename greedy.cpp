/*************************************************************************
    > File Name: greedy.cpp
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sat Oct 22 19:43:37 2016
 ************************************************************************/

#include "functions.h"
#include<queue>
#include<map>

bool check_exist(int v, const vector<int> &seeds){
    for(int i=0;i<seeds.size();i++){
        if(v==seeds[i]) return true;
    }
    return false;
}

bool check_queues_empty(map<int, queue<LevelNode> > &qs){
    map< int,queue<LevelNode> >::iterator it;
    for(it=qs.begin();it!=qs.end();++it){
        if(it->second.empty()==false){
            return false;
        }
    }
    return true;
}

void get_inf_matrix(const Graph &graph, Users &users, vector< vector<double> > &inf_matrix){
    for(int i=0;i<graph.size();i++){
        vector<double> temp;
        inf_matrix.push_back(temp);
        for(int j=0;j<graph.size();j++){
            inf_matrix[i].push_back(0);
        }

        for(int k=0;k<graph[i].size();k++){
            inf_matrix[i][graph[i][k].to] = graph[i][k].to;
        }
    }
}

double get_overall_opinion(const vector< vector<double> > &inf_matrix, const Graph &graph, Users &users, const vector<int> &seeds){

    vector<double> user_weights;

    Users temp_users = users;

    for(int i=0;i<temp_users.size();i++){
        user_weights.push_back(0.0);
    }

    map< int,queue<LevelNode> > qs;
    for(int i=0;i<seeds.size();i++){
        queue<LevelNode> q;
        LevelNode node;
        node.id = seeds[i];
        node.level = 0;
        q.push(node);
        qs[seeds[i]] = q;
    }

    int level = 0;
    while(check_queues_empty(qs)==false){
        map< int,vector<int> > neighbors;

        for(int s=0;s<seeds.size();s++){
            while(qs[seeds[s]].empty()==false && qs[seeds[s]].front().level==level){
                int  cur_node = qs[seeds[s]].front().id;
                qs[seeds[s]].pop();
                for(int k=0;k<graph[cur_node].size();k++){
                    int neighbor = graph[cur_node][k].to;
                    if(temp_users[neighbor].activation_status==false){
                        user_weights[neighbor]+=inf_matrix[cur_node][neighbor];
                        neighbors[seeds[s]].push_back(neighbor);
                    }
                    else continue;
                }
            }
        }

        //find activated neighbors
        for(int s=0;s<seeds.size();s++){
            for(int j=0;j<neighbors[seeds[s]].size();j++){
                int neighbor = neighbors[seeds[s]][j];
                if(user_weights[neighbor]>users[neighbor].activation_threshhold){
                    temp_users[neighbor].activation_status = true;
                    temp_users[neighbor].opinion+=temp_users[seeds[s]].opinion*inf_matrix[seeds[s]][neighbor];
                    LevelNode node;
                    node.id = neighbor;
                    node.level = level+1;                   
                    qs[seeds[s]].push(node);
                }
            }
        }
        level++;
    }

    double all_opinion=0.0;
    for(int i=0;i<temp_users.size();i++){
        all_opinion+=temp_users[i].opinion;
    }

    return all_opinion;
}

void greedy(const Graph &graph, Users &users, int k){
    vector< vector<double> > inf_matrix;
    get_inf_matrix(graph, users,inf_matrix);

    vector<int> seeds;
    for(int i=0;i<k;i++){
         double max_marg_opinion = 0.0;
         int new_seed=0;
         for(int j=0;j<graph.size();j++){
             if(check_exist(i, seeds)==true) continue;
             double old_opinion = get_overall_opinion(inf_matrix, graph, users, seeds);
             seeds.push_back(j);
             double new_opinion = get_overall_opinion(inf_matrix, graph, users, seeds);
             seeds.pop_back();
             double cur_marg_opinion = new_opinion-old_opinion;
             if(cur_marg_opinion>max_marg_opinion){
                 max_marg_opinion = cur_marg_opinion;
                 new_seed = j;
             }
         }
         if(max_marg_opinion>0) seeds.push_back(new_seed);
         else if(max_marg_opinion==0) return;
    }
}
