/*************************************************************************
    > File Name: functions.h
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sat Oct 22 19:38:16 2016
 ************************************************************************/

#include "graph.h"

void greedy(const Graph &graph, Users &users);
double get_overall_opinion(const Graph &graph, Users &users, const vector<int> &seeds);
double get_my_overall_opinion(const Graph &graph, Users &users, const vector<int> &seeds);
