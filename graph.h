/*************************************************************************
    > File Name: graph.h
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sat Oct 22 14:44:59 2016
 ************************************************************************/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

#define INFINITE 1<<29

struct Vertex{
    int id;
    string name;
    double activation_threshhold;
    double opinion;
    bool activation_status;
    int in_degree;
    int out_degree;
};

struct Edge{
    int from;
    int to;
    double weight;
};

struct Node{
    int id;
    int level;
};

typedef vector<Vertex> Users;
typedef vector< vector<Edge> > Graph;
typedef vector< vector<int> > Distances;
typedef struct Node LevelNode;

void get_all_pair_shortest_path(Graph &graph, Distances &dist){
    for(int i=0;i<graph.size();i++){
        vector<int> neightbors;
        dist.push_back(neightbors);
        for(int j=0;j<graph.size();j++){
            if(i==j) dist[i].push_back(0);
            else dist[i].push_back(INFINITE);
        }
    }

    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph[i].size();j++){
            dist[i][graph[i][j].to]=1;
        }
    }

    for(int k=0;k<graph.size();k++){
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph.size();j++){
                if(i==j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][i]);
            }
        }
    }

    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph.size();j++){
            if(dist[i][j]>=INFINITE) dist[i][j] = -1;
            cout<<i<<" to "<<j<<" dist:"<<dist[i][j]<<endl;
        }
    }
}
