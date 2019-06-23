#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <string>

using namespace std;

struct Node
{
    int val;
    vector <int> adj;
    Node(int a){val = a;}
};

struct Edge
{
    int src, dest;
};

class myGraph
{
    public:
        myGraph();
        myGraph(string);
        virtual ~myGraph();
        int getNodes() {return graph.size();}
        int getEdges() {return edgeNum;}
        bool insertGraph(int,int);
        void printGraph(ofstream& ofile);
        bool deleteGraph(int,int);
        void shortestPath(int,int);
        void connectedComp();
        void getSize();


    protected:

    private:

        bool existsEdge(int,int);
        int existsNode(int);
        int edgeNum = 0;
        void DFS(int, vector<vector<int>>&,int&,ofstream&);
        vector <Node*> graph;
        vector <Edge*> edgeList;
};

#endif // MYGRAPH_H
