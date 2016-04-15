#include <iostream>
#include <queue>
#include <list>
#include <stack>

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
stack<int> leaveSeq;

void DFS_visit(Graph G, int u);
void SCC_visit(Graph GT, int u);

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
    leaveSeq.push(u);
}

void Print_DFS(Graph G)
{
    for(int i = 1; i < G.V; i++)
        cout << "vertex: " << i << ", d = " << G.node[i].d << ", f = " << G.node[i].f << endl;
}

Graph GetGraphTransposition(Graph G)
{
    Graph GT = Graph(G.V - 1);

    for(int c = 1; c < GT.V; c++)
        GT.node[c] = G.node[c];

    list<int>::iterator i;

    for(int c = 1; c < GT.V; c++)
        for(i = G.adj[c].begin(); i != G.adj[c].end(); i++)
            GT.adj[*i].push_back(c);

    return GT;
}

void SCC(Graph G)
{
    DFS(G);
    Graph GT = GetGraphTransposition(G);
    for(int i = 1; i < GT.V; i++)
        GT.node[i].color = 0;

    while(!leaveSeq.empty())
    {
        int tmp = leaveSeq.top();
        leaveSeq.pop();
        if(GT.node[tmp].color == 0)
        {
            cout << "SCC Group:\t";
            SCC_visit(GT, tmp);
            cout << endl;
        }

    }
}

void SCC_visit(Graph GT, int u)
{
    GT.node[u].color = 2;
    cout << u << "\t";
    list<int>::iterator i;
    for(i = GT.adj[u].begin(); i != GT.adj[u].end(); i++)
    {
        if(GT.node[*i].color == 0)
            SCC_visit(GT, *i);
    }
}

int main()
{
    //build the graph
    Graph G = Graph(8);
    G.AddEdge(1,2);
    G.AddEdge(2,3);
    G.AddEdge(2,5);
    G.AddEdge(2,6);
    G.AddEdge(3,4);
    G.AddEdge(3,7);
    G.AddEdge(4,3);
    G.AddEdge(4,8);
    G.AddEdge(5,1);
    G.AddEdge(5,6);
    G.AddEdge(6,7);
    G.AddEdge(7,6);
    G.AddEdge(7,8);
    G.AddEdge(8,8);

    SCC(G);
    return 0;
}
