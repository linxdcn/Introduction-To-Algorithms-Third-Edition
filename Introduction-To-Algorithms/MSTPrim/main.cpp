#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>
#include <map>
#include <queue>

using namespace std;

#define Max numeric_limits<int>::max();

class Edge
{
public:
    int s;
    int e;
    int w;

    Edge(int s, int e, int w) : s(s), e(e), w(w){}
};

bool EdgeCompare(Edge i, Edge j)
{
    return i.w < j.w;
}

class Vertex
{
public:
    int key;
    int pre;
    int id;

    Vertex() : key(0), pre(-1), id(0) {}
};

bool operator < (Vertex a, Vertex b)
{
    return a.key > b.key;
}

class Graph
{
public:
    int V;
    vector<Vertex> Ver;
    vector<vector<int>> Adj;

    Graph(int v)
    {
        vector<Vertex>::size_type num1 = v;
        vector<int>::size_type num2 = v;

        V = v;
        Ver = vector<Vertex>(num1);
        for(int i = 0; i < v; i++)
        {
            Ver[i].id = i;
            vector<int> row = vector<int>(num2);
            Adj.push_back(row);
        }
    }

    void AddEdge(int s, int e, int w)
    {
        Adj[s - 1][e - 1] = w;
    }

    void AddUndirectedEdge(int s, int e, int w)
    {
        AddEdge(s, e, w);
        AddEdge(e, s, w);
    }
};

void MSTPrim(Graph G, int s)
{
    map<int, int> vertexMap;
    for(int i = 0; i < G.V; i++)
    {
        G.Ver[i].key = Max;
        vertexMap.insert(pair<int, int>(i,1));
    }

    G.Ver[s].key = 0;

    //sort all the edges
    vector<Edge> result;
    priority_queue<Vertex> allVertex;
    for(int i = 0; i < G.V; i++)
        allVertex.push(G.Ver[i]);

    //define iterator
    vector<Edge>::iterator iterEdge;
    map<int, int>::iterator iterMap;
    while(!allVertex.empty())
    {
        Vertex ver = allVertex.top();
        int node = ver.id;
        if(G.Ver[node].pre != -1)
            result.push_back(Edge(G.Ver[node].pre, node, G.Ver[node].key));
        allVertex.pop();
        vertexMap.erase(node);
        for(int i = 0; i < G.V; i++)
            if(G.Adj[node][i] != 0 && vertexMap.count(i) != 0 && G.Adj[node][i] < G.Ver[i].key)
            {
                G.Ver[i].key = G.Adj[node][i];
                G.Ver[i].pre = node;
            }
        allVertex = priority_queue<Vertex>();
        for(iterMap = vertexMap.begin(); iterMap != vertexMap.end(); iterMap++)
            allVertex.push(G.Ver[iterMap->first]);
    }

    //output result
    for(iterEdge = result.begin(); iterEdge != result.end(); iterEdge++)
        cout << iterEdge->s +1 << "\t" << iterEdge->e + 1 << "\t" << iterEdge->w << endl;
}

int main()
{
    Graph G = Graph(9);
    G.AddUndirectedEdge(1, 2, 4);
    G.AddUndirectedEdge(1, 8, 8);
    G.AddUndirectedEdge(2, 8, 11);
    G.AddUndirectedEdge(2, 3, 8);
    G.AddUndirectedEdge(3, 9, 2);
    G.AddUndirectedEdge(9, 8, 7);
    G.AddUndirectedEdge(7, 9, 6);
    G.AddUndirectedEdge(7, 8, 1);
    G.AddUndirectedEdge(3, 4, 7);
    G.AddUndirectedEdge(6, 7, 2);
    G.AddUndirectedEdge(3, 6, 4);
    G.AddUndirectedEdge(4, 5, 9);
    G.AddUndirectedEdge(5, 6, 10);
    G.AddUndirectedEdge(4, 6, 14);

    MSTPrim(G, 0);
    return 0;
}
