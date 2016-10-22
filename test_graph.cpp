/*************************************************************************
    > File Name: test_graph.cpp
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sat Oct 22 14:52:22 2016
 ************************************************************************/

#include "graph.h"

int main(){

    Graph g;
    Users u;

    for(int i=0;i<10;i++){
        Vertex v;
        v.id = i;
        v.name = "test";
        v.activation_threshhold = 1;
        v.activation_status = false;
        v.opinion = 0;
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
            e.weight = 0.5;
            g[i].push_back(e);
        }
    }

    // for(int i=0;i<u.size();i++){
    //     for(int j=0;j<g[i].size();j++){
    //         cout<<"from "<<i<<" to "<<j<<" weight:"<<g[i][j].weight<<endl;
    //     }
    // }

    Distances dist;

    get_all_pair_shortest_path(g, dist);

    for(int i=0;i<g.size();i++){
        for(int j=0;j<g[i].size();j++){
            cout<<i<<" to "<<j<<" is "<<dist[i][j]<<endl;
        }
    }

    return 0;
}

