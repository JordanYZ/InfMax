/*************************************************************************
    > File Name: file_2_graph.h
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sat Oct 22 16:08:28 2016
 ************************************************************************/

#include "graph.h"

class FileToGraph{
public:
    explicit FileToGraph(const string file_name): file_name(file_name){};
    ~FileToGraph();
    void convert();
    void get_graph(Graph &g);
    void get_users(Users &u);
// protected:
    double get_weight();
    double get_opinion();
private:
    string file_name;
    Graph graph;
    Users users;
    vector< vector<int> > from_to_edges;
    vector< vector<int> > to_from_edges;
};