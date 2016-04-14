#include <iostream>
#include <queue>
#include <list>

using namespace std;

class Node
{
public:
    int color; //0:white, 1:gray, 2:black
    int pre; //predecessor
    int d; //begin time
    int f; //end time
};

class Graph
{
public:
    int V;
    list<int> *adj;
    Node *node;

    Graph(int v)
    {
        V = v + 1;
        adj = new list<int>[v + 1];
        node = new Node[v + 1];
    }

    void AddEdge(int v, int u)
    {
        adj[v].push_back(u);
    }
};

int time = 0;
void DFS_visit(Graph G, int u);

void DFS(Graph G)
{
    for(int i = 1; i < G.V; i++)
    {
        G.node[i].color = 0;
        G.node[i].pre = -1;
    }
    for(int i = 1; i < G.V; i++)
        if(G.node[i].color == 0)
            DFS_visit(G, i);
}

void DFS_visit(Graph G, int u)
{
    time++;
    G.node[u].d = time;
    G.node[u].color = 1;
    list<int>::iterator i;
    for(i = G.adj[u].begin(); i != G.adj[u].end(); i++)
    {
        if(G.node[*i].color == 0)
        {
            G.node[*i].pre = u;
            DFS_visit(G, *i);
        }
    }
    time++;
    G.node[u].color = 2;
    G.node[u].f = time;
}

void Print_DFS(Graph G)
{
    for(int i = 1; i < G.V; i++)
        cout << "vertex: " << i << ", d = " << G.node[i].d << ", f = " << G.node[i].f << endl;
}
int main()
{
    //build the graph
    Graph G = Graph(6);
    G.AddEdge(1,2);
    G.AddEdge(1,4);
    G.AddEdge(2,5);
    G.AddEdge(3,5);
    G.AddEdge(3,6);
    G.AddEdge(4,2);
    G.AddEdge(5,4);
    G.AddEdge(6,6);

    DFS(G);
    Print_DFS(G);
    return 0;
}
