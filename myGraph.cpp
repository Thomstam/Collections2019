#include "myGraph.h"
#include <cassert>

using namespace std;
using namespace std::chrono;

/**Template function to recreate "pop_front"
Used in function "shortestPath"**/
template<typename T>
void pop_front(vector<T>& vec)
{
    assert(!vec.empty());
    vec.erase(vec.begin());
}

myGraph::myGraph() = default;
myGraph::myGraph(string filename)
{
    auto start = steady_clock::now();
    ofstream ofile;
    ofile.open("output.txt", ios::out | ios::app);
    int a,b;
    int ctr = 0;
    Node* ptr;
    int temp;
    ifstream ifile;
    ifile.open(filename);
    if (ifile.is_open())
    {
        while (ifile >> a >> b)
        {
            if (a == b || existsEdge(a,b)) /** Checking if edge is already in the Graph**/
                continue;
            temp = existsNode(a);
            if (temp >= 0) /** If Node a exists already, just push Node b to a's adjacency vector**/
                graph[temp] -> adj.push_back(b);
            else
            {
                ptr = new Node(a); /** If Node a doesn't exist, allocate memory for it, and push b as adjacent Node**/
                graph.push_back(ptr);
                graph[ctr] -> adj.push_back(b);
                ++ctr;
            }
            temp = existsNode(b);
            if (temp >= 0) /** If Node b exists already, just push Node a to b's adjacency vector**/
                graph[temp] -> adj.push_back(a);
            else
            {
                ptr = new Node(b); /** If Node b doesn't exist, allocate memory for it, and push a as adjacent Node**/
                graph.push_back(ptr);
                graph[ctr] -> adj.push_back(a);
                ++ctr;
            }
            ++edgeNum;
        }
    }
    else
        ofile<<"Couldn't locate "<<filename<<endl;
    printGraph(ofile);
    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();
    ofile << "\nTime taken to build Graph: '" << ftime << "' microseconds.\n\n";
    ofile.flush();
    ofile.close();
    ifile.close();
}

myGraph::~myGraph()
{
    /**Destructor to free dynamically allocated memory**/
    for (int i =0; i< graph.size(); i++)
        delete (graph[i]);
   graph.clear();
}

bool myGraph::existsEdge(int a, int b)
{
    /** Edge existence checker.
    Returns, True if found.**/
    for (int i = 0; i<graph.size(); ++i)
    {
        if (graph[i] -> val == a)
            for (int j=0; j < graph[i] -> adj.size(); ++j)
                if (graph[i] -> adj[j] == b)
                    return true;
        if (graph[i] -> val == b)
            for (int x=0; x < graph[i] -> adj.size(); ++x)
                if (graph[i] -> adj[x] == a)
                    return true;
    }
    return false;
}

int myGraph::existsNode(int key)
{
    /** Node existence checker.
    Returns, Node's position if found.**/
    for (int i = 0; i< graph.size(); ++i)
        if (graph[i] -> val == key)
            return i;
    return -1;
}

void myGraph::printGraph(ofstream& ofile)
{
    /** full graph printer**/
    for (int i = 0; i < graph.size(); ++i)
    {
        ofile<< graph[i] -> val <<" --> ";
            for (int j = 0; j<graph[i] -> adj.size(); ++j)
                ofile<< graph[i] -> adj[j]<<" ";
        ofile<<endl;
    }
    ofile<<"Nodes are: "<<getNodes()<<" Edges are: "<<getEdges()<<endl;
}

bool myGraph::insertGraph(int a, int b)
{
    auto start = steady_clock::now();
    ofstream ofile;
    ofile.open("output.txt", ios::out | ios::app);
    /** checking legitimacy of request **/
    if (a == b || existsEdge(a,b))
        return 0;
    int temp;
    int pos = graph.size();
    Node* ptr;
    /** temp gets assigned with the position of Node a.
    Through the pointer in vector Graph, we push back value b
    to the Node's adjacency vector **/
    temp = existsNode(a);
    if (temp >= 0)
            graph[temp] -> adj.push_back(b);
    else
    {
        ptr = new Node(a);
        graph.push_back(ptr);
        graph[pos] -> adj.push_back(b);
        ++pos;
    }
    /** temp gets assigned with the position of Node b.
    Through the pointer in vector Graph, we push back value a
    to the Node's adjacency vector **/
    temp = existsNode(b);
    if (temp >= 0)
        graph[temp] -> adj.push_back(a);
    else
    {
        ptr = new Node(b);
        graph.push_back(ptr);
        graph[pos] -> adj.push_back(a);
        ++pos;
    }
    ++edgeNum;
    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();
    ofile << "\nTime taken to insert Edge: '" << ftime << "' microseconds.\n\n";
    ofile.flush();
    ofile.close();
    return 1;
}

bool myGraph::deleteGraph(int a, int b)
{
    auto start = steady_clock::now();
    ofstream ofile;
    ofile.open("output.txt", ios::out | ios::app);
    /** checking legitimacy of request **/
    if (a == b)
        return 0;
    if (!existsEdge(a,b))
        return 0;

    for (int i=0; i<graph.size(); ++i)
    {
        if (graph[i] -> val == a)
            for (int j=0; j < graph[i] -> adj.size(); ++j)
                if (graph[i] -> adj[j] == b)
                    graph[i] -> adj.erase(graph[i] -> adj.begin() + j);
        if (graph[i] -> val == b)
            for (int j=0; j < graph[i] -> adj.size(); ++j)
                if (graph[i] -> adj[j] == a)
                    graph[i] -> adj.erase(graph[i] -> adj.begin() + j);
    }
    --edgeNum;
    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();
    ofile << "\nTime taken to Delete Edge: '" << ftime << "' microseconds.\n\n";
    ofile.flush();
    ofile.close();
    return 1;
}

void myGraph::shortestPath(int src, int dst)
{
    auto start = steady_clock::now();
    ofstream ofile;
    ofile.open("output.txt", ios::out | ios::app);

    /** Checking legitimacy of request **/
    if (src == dst){
        auto stop = steady_clock::now();
        auto ftime = duration_cast<microseconds>(stop - start).count();
        ofile.flush();
        ofile.close();
        return;}

    /** Initializing 2D vectors for Distance, and for Visited Nodes.
    Every Nodes distance from Source will start at INT_MAX, and every
    Node will be unvisited. Source Node will have distance 0 and will
    be marked as Visited **/
    vector<vector<int>> dist;
    dist.resize(getNodes(), vector<int>(2, INT_MAX));
    vector<vector<int>> visited;
    visited.resize(getNodes(), vector<int>(2, 0));
    vector<vector<int>> pred;
    pred.resize(getNodes(), vector<int>(2, INT_MIN));
    for (int i=0; i < graph.size(); ++i)
    {
        dist[i][0] = graph[i]->val;
        if (dist[i][0] == src)
            dist[i][1] = 0;
        visited[i][0] = graph[i]->val;
        if (visited[i][0] == src)
            visited[i][1] = 1;
        pred[i][0] = graph[i]->val;
    }
    /** Traversing the tree, using BFS. Weight of each Edge, will be: 1 **/
    vector<int> q;
    q.push_back(src);
    while (!q.empty())
    {
        for (int pos = 0; pos < graph.size(); ++pos)
            if (graph[pos] -> val == q.front())
            {
                pop_front(q);
                for (int i = 0; i < graph[pos] -> adj.size(); ++i)
                    for (int j = 0; j < visited.size(); ++j)
                    {
                        if (visited[j][0] == graph[pos] -> adj[i] && visited[j][1] == 0)
                        {
                            visited[j][1] = 1;
                            if (dist[j][1] > dist[pos][1] + 1) /** Relaxation condition**/
                            {
                                dist[j][1] = dist[pos][1] + 1; /** Relaxation from INT_MAX **/
                                pred[j][i] = graph[pos] -> val;

                                q.push_back(visited[j][0]);
                                if (visited[j][0] == dst){
                                    ofile<<"Shortest Path Length from "<<src<<" to "<<dst<<" is: "<< dist[j][1];
                                    auto stop = steady_clock::now();
                                    auto ftime = duration_cast<microseconds>(stop - start).count();
                                    ofile << "\nTime taken to build MinHeap: '" << ftime << "' microseconds.\n\n";
                                    ofile.flush();
                                    ofile.close();
                                    return;}
                            }
                        }
                    }
            }
    }
    if (q.empty())
        ofile<<"Couldn't find a path."<<endl;
        auto stop = steady_clock::now();
        auto ftime = duration_cast<microseconds>(stop - start).count();
        ofile << "\nTime taken to build MinHeap: '" << ftime << "' microseconds.\n\n";
        ofile.flush();
        ofile.close();
}

void myGraph::connectedComp()
{
    auto start = steady_clock::now();
    ofstream ofile;
    ofile.open("output.txt", ios::out | ios::app);

    int ctr; /** Cost counter**/
    vector<vector<int>> visited;
    visited.resize(getNodes(), vector<int>(2, 0));
    for (int i=0; i < graph.size(); ++i)
        visited[i][0] = graph[i]->val;
    ofile<<endl<<"\nConnected Components are:\n";
    for (int i=0; i < graph.size(); ++i)
    {
        ctr = 0;
        if (visited[i][1] == 0)
        {
            DFS(i, visited, ctr,ofile); /** Recursive DFS traversal**/
            ofile<<" End of Connection. Cost of component: "<<ctr<<endl;
        }
    }
    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();
    ofile << "\nTime taken to find Connected Components: '" << ftime << "' microseconds.\n\n";
    ofile.flush();
    ofile.close();
}

void myGraph::DFS(int pos, vector<vector<int>>& visited, int& ctr, ofstream& ofile)
{
    visited[pos][1] = 1;
    ofile<< visited[pos][0] <<" -- ";
    for (int i = 0; i < graph[pos] -> adj.size(); ++i)
        for (int j = 0; j < visited.size(); ++j)
            if ( graph[pos] -> adj[i] == visited[j][0] && visited[j][1] == 0)
            {
                ++ctr;
                DFS(j, visited, ctr, ofile);
            }
}

void myGraph::getSize()
{
    auto start = steady_clock::now();
    ofstream ofile;
    ofile.open("output.txt", ios::out | ios::app);
    ofile<<"Nodes are: "<<getNodes()<<endl<<"Edges are: "<<getEdges()<<endl;
    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();
    ofile << "\nTime taken to getSize: '" << ftime << "' microseconds.\n\n";
    ofile.flush();
    ofile.close();
}
