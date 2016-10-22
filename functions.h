/*************************************************************************
    > File Name: functions.h
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sat Oct 22 19:38:16 2016
 ************************************************************************/

#include "graph.h"
#include<queue>
#include<map>

bool check_exist(int v, const vector<int> &seeds);
bool check_queues_empty(const map<int, queue<LevelNode> > &qs);
void get_inf_matrix(const Graph &graph, const Users &users, vector< vector<double> > &inf_matrix);
double get_overall_opinion(const vector< vector<double> > &inf_matrix, const Graph &graph, const Users &users, const vector<int> &seeds);
void greedy(const Graph &graph, const Users &users, int k, vector<int> &seeds);