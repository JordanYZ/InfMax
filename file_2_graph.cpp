/*************************************************************************
    > File Name: file_2_graph.cpp
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sat Oct 22 16:02:51 2016
 ************************************************************************/

#include "file_2_graph.h"
#include <stdio.h>  
#include <sys/time.h>
#include <time.h> 

FileToGraph::~FileToGraph(){}

void FileToGraph::convert(){
    // ifstream infile(file_name);

    // string line;
    // while (std::getline(infile, line))
    // {
    //     std::istringstream iss(line);
    //     int a, b;
    //     if (!(iss >> a >> b)) { break; } // error

    //     // process pair (a,b)
    // }    
}

void FileToGraph::get_graph(Graph &g){
    g = graph;
}

void FileToGraph::get_users(Users &u){
    u = users;
}

double FileToGraph::get_weight(){
    struct timeval t_val;
    gettimeofday(&t_val, NULL);

    srand((unsigned)t_val.tv_usec);
    double weight = rand()/(double)(RAND_MAX);//(rand()%1000)*0.01;
    return weight;
}

double FileToGraph::get_opinion(){
    struct timeval t_val;
    gettimeofday(&t_val, NULL);

    srand((unsigned)t_val.tv_usec);
    double opinion = rand()/(double)(RAND_MAX);//(rand()%1000)*0.01;
    return opinion;
}

int main(){
    FileToGraph f2g("test");

    for(int i=0;i<100;i++){
        cout<<f2g.get_weight()<<" "<<f2g.get_opinion()<<endl;
    }
    return 0;
}



