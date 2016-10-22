/*************************************************************************
    > File Name: greedy.cpp
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sat Oct 22 19:43:37 2016
 ************************************************************************/

#include "functions.h"

bool check_exist(int v, const vector<int> &seeds){
    for(int i=0;i<seeds.size();i++){
        if(v==seeds[i]) return true;
    }
    return false;
}

void greedy(const Graph &graph, Users &users, int k){
    vector<int> seeds;
    for(int i=0;i<k;i++){
         double max_marg_opinion = 0.0;
         int new_seed=0;
         for(int j=0;j<graph.size();j++){
             if(check_exist(i, seeds)==true) continue;
             double old_opinion = get_overall_opinion(graph, users, seeds);
             seeds.push_back(j);
             double new_opinion = get_overall_opinion(graph, users, seeds);
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
