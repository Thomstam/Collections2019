#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <Map>
#include <fstream>
#include <list>
#include <chrono>
#include <string>

using namespace std;

class Graph
{
    public:
        Graph(string);
        virtual ~Graph();
        bool insertGraph(int, int);

        bool deleteEdge(int, int);

        void shortestPath(int,int);

        void MST();

        void connectedComp();

    protected:

    private:
        map <int, vector<int>> graph;

        bool BFS(int, int, map<int,int>&, map<int,int>&, ofstream&);

        bool BFS(int, map<int,int>&, ofstream&);

        void DFS(int, map<int,bool>&, ofstream&);
};

#endif // GRAPH_H
