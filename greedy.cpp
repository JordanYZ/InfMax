/*************************************************************************
    > File Name: greedy.cpp
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sat Oct 22 19:43:37 2016
 ************************************************************************/

#include "functions.h"

void greedy(const Graph &graph, const Users &users, int k, vector<int> &seeds){
    vector< vector<double> > inf_matrix;
    get_inf_matrix(graph, users,inf_matrix);

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
             cout<<j<<" as seed, marginal opiion:"<<cur_marg_opinion<<endl;
             if(cur_marg_opinion>max_marg_opinion){
                 max_marg_opinion = cur_marg_opinion;
                 new_seed = j;
             }
         }
         if(max_marg_opinion>0) seeds.push_back(new_seed);
         else if(max_marg_opinion==0) return;
    }
}

int main(){

    Graph g;
    Users u;

    for(int i=0;i<10;i++){
        Vertex v;
        v.id = i;
        v.name = "test";
        v.activation_threshhold = 1;
        v.activation_status = false;
        v.opinion = 0.1*i/2;
        u.push_back(v);
    }

    for(int i=0;i<u.size();i++){
        vector<Edge> edges;
        g.push_back(edges);
        for(int j=0;j<u.size();j++){
            if(i==j) continue;
            Edge e;
            e.from = i;
            e.to = j;
            e.weight = 0.5*i;
            g[i].push_back(e);
        }
    }

    vector<int> seeds;

    greedy(g, u, 2, seeds);

    for(int s=0;s<seeds.size();s++){
        cout<<"seed: "<<seeds[s]<<endl;
    }

    return 0;
}
