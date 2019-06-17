#include "Graph.h"

using namespace std::chrono;
using namespace std;

Graph::Graph(string filename)
{
    auto start = steady_clock::now();

    int a,b;
    vector<int>::iterator it;
    std::map<int, vector<int>>::iterator m;
    ifstream ifile;
    ifile.open(filename);
    if (ifile.is_open())
    {
        while (ifile >> a >> b)
        {
            if(a==b)
            continue;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

    std::ofstream ofile;
    ofile.open("output.txt", std::ios::out | std::ios::app);

    std::map<int, vector<int>>::iterator print;
    std::vector<int>::iterator pr;
    ofile<<endl;

    for(print = graph.begin(); print!= graph.end(); ++print){
    ofile << print->first<< ": ";
    for(pr = print->second.begin(); pr!=print->second.end(); ++pr)
    ofile<< *pr<<" ";
    ofile<<endl;}
    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();
    ofile << "\nTime taken to build MinHeap: '" << ftime << "' microseconds.\n\n";
    ofile.flush();
    ofile.close();
    ifile.close();


    }
    else cout << "Unable to open file";
}

Graph::~Graph()
{
    //dtor
}

bool Graph::insertGraph(int a, int b)
{
    std::ofstream ofile;
    ofile.open("output.txt", std::ios::out | std::ios::app);

    auto start = steady_clock::now();
    if(a==b)
    {
        ofile<<"Can't add edge: "<<a<<" -- "<<b<<endl<<"This is an acyclic graph. ";
        return 0;
    }
    std::map<int, vector<int>>::iterator m = graph.find(a);
    std::vector<int>::iterator it;
    if (m != graph.end())
    {
        for( it = m->second.begin(); it != m->second.end(); ++it)
            if ( *it == b)
            {
                ofile<<"Edge "<<a<<" -- "<<b<<" already exists "<<endl;
                return 0;
            }
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    else
    {
        graph[a].push_back(b);
        graph[b].push_back(a);

    }

    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();
    ofile << "\nTime taken to insert Edge: '" << ftime << "' microseconds.\n\n";
    ofile.flush();
    ofile.close();
    return 1;
}

bool Graph::deleteEdge(int a, int b)
{
    auto start = steady_clock::now();
    std::ofstream ofile;
    ofile.open("output.txt", std::ios::out | std::ios::app);

    std::map<int, vector<int>>::iterator m = graph.find(a);
    std::map<int, vector<int>>::iterator p = graph.find(b);
    std::vector<int>::iterator it;
    std::vector<int>::iterator ip;
    if (m != graph.end() && p!=graph.end())
    {
        ofile<<"Deleting edge: "<<a<<" -- "<<b<<endl;
        for( it = m->second.begin(); it != m->second.end(); ++it)
            if ( *it == b)
            {
                m->second.erase(it);
                if (m->second.begin() == m->second.end())
                    graph.erase(m);
                break;
            }
        for (ip = p->second.begin(); ip != p->second.end(); ++ip)
            if ( *ip == a)
            {
                p->second.erase(ip);
                if (p->second.begin() == p->second.end())
                    graph.erase(p);
                break;
            }
        auto stop = steady_clock::now();
        auto ftime = duration_cast<microseconds>(stop - start).count();
        ofile << "\nTime taken to delete Edge: '" << ftime << "' microseconds.\n\n";
        ofile.flush();
        ofile.close();
        return 1;
    }
    else
    {
        cout<<"Edge "<<a<<" -- "<<b<<" does not exist. "<<endl;
        return 0;
    }
}

//BFS FOR SHORTEST PATH
bool Graph::BFS(int src, int dst, map<int,int>& dist, map<int,int>& pred, ofstream& ofile)
{
    map<int, vector<int>>::iterator it;
    vector<int>::iterator m;
    map<int, bool> color;
    //Priority queue, to implement Breadth First Search.
    list<int> q;
    //predecessor map, initialized to INT_MIN
    //distance map, initialized to INT_MIN
    //Map for already visited keys, initialized to false;
    for (it = graph.begin(); it!=graph.end(); ++it)
    {
        dist[it->first] = INT_MAX;
        color[it->first] = false;
        pred[it->first] = INT_MIN;
    }
    color[src] = true;
    dist[src] = 0;
    q.push_back(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop_front();
        for (m = graph[u].begin(); m!= graph[u].end(); ++m)
        {
            if (color[*m] == false)
            {
                color[*m] = true;
                if (dist[*m] > dist[u]+1)
                {
                    dist[*m] = dist[u] + 1;
                    pred[*m] = u;
                    q.push_back(*m);

                    if (*m == dst)
                        return 1;
                }
            }
        }
    }
    return 0;
}

void Graph::shortestPath(int src, int dst)
{
    auto start = steady_clock::now();

    std::ofstream ofile;
    ofile.open("output.txt", std::ios::out | std::ios::app);

    map<int, int> dist;
    map<int, int> pred;
    if(BFS(src, dst, dist, pred, ofile) == 0)
    {
        ofile<<"Couldn't find a viable path. ";
        return;
    }
    vector <int>path;
    int way = dst;
    path.push_back(way);
    while (pred[way] != INT_MIN)
        {
        path.push_back(pred[way]);
        way = pred[way];
        }
    ofile << "Shortest path length is : "<< dist[dst];
    //printing path from source to destination
    ofile << "\nPath is: ";
    for (int i = path.size() - 1; i >= 0; i--)
        ofile << path[i] << " ";

    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();

    ofile << "\nTime taken to find Shortest Path: '" << ftime << "' microseconds.\n\n";
    ofile.flush();
    ofile.close();
    return;
}

void Graph::MST()
{
    auto start = steady_clock::now();

    std::ofstream ofile;
    ofile.open("output.txt", std::ios::out | std::ios::app);

    map<int, int> pred;
    map<int,vector<int>>::iterator its;
    its = graph.begin();
    BFS(its->first, pred, ofile);
    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();
    ofile << "\nTime taken to find MST: '" << ftime << "' microseconds.\n\n";
    ofile.flush();
    ofile.close();
    return;
}

//BFS FOR MST (SRC AND DESTINATION DOES NOT MATTER)
bool Graph::BFS(int src, map<int,int>& pred, ofstream& ofile)
{
    int count = 0;
    map<int, vector<int>>::iterator it;
    map<int, int>::iterator temp;
    vector<int>::iterator m;

    map<int, bool> color;
    list<int> q;

    //predecessor map, initialized to INT_MIN
    //Map for already visited keys, initialized to false;

    for (it = graph.begin(); it!=graph.end(); ++it)
    {
        color[it->first] = false;
        pred[it->first] = INT_MIN;
    }
    color[src] = true;
    q.push_back(src);
    while (!q.empty())
    {
        ++count;
        int u = q.front();
        q.pop_front();
        for (m = graph[u].begin(); m!= graph[u].end(); ++m)
            if (color[*m] == false)
            {
                color[*m] = true;
                pred[*m] = u;
                q.push_back(*m);
            }
    }
    for (temp = pred.begin(); temp!=pred.end(); ++temp)
        if (temp->first != src && temp->second == INT_MIN)
        {
            ofile<<"There is no MST. Graph is not connected."<<endl;
            return 0;
        }
    ofile<<"Mst cost is: "<<count - 1<<endl<<"Mst's edges are: "<<endl;
    for (temp = pred.begin(); temp!=pred.end(); ++temp)
        if (temp->second != INT_MIN)
            ofile<<temp->first<<" -- "<<temp->second<<endl;
    return 1;
}

void Graph::connectedComp()
{
    auto start = steady_clock::now();

    std::ofstream ofile;
    ofile.open("output.txt", std::ios::out | std::ios::app);

    map<int,vector<int>>::iterator it;
    map<int,bool> visited;
    for(it=graph.begin(); it!=graph.end(); ++it)
        visited[it->first] = false;

    ofile<<endl<<"\nConnected Components are:\n";
    for(it=graph.begin(); it!=graph.end(); ++it)
        if (visited[it->first] == false)
        {
            DFS(it->first, visited, ofile);
            ofile<<"End.\n\n";
        }
    auto stop = steady_clock::now();
    auto ftime = duration_cast<microseconds>(stop - start).count();
    ofile << "\nTime taken to find Connected Components: '" << ftime << "' microseconds.\n\n";
    ofile.flush();
    ofile.close();
}

void Graph::DFS(int v, map<int,bool>& visited, ofstream& ofile)
{
    vector<int>::iterator it;
    visited[v] = true;
    ofile<< v << " -- ";
    for (it = graph[v].begin(); it != graph[v].end(); ++it)
        if (visited[*it] == false)
            DFS(*it, visited, ofile);
}



