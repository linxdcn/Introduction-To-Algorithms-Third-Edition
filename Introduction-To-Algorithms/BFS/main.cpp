#include <iostream>
#include <queue>
#include <list>

using namespace std;

class Node
{
public:
    int color; //0:white, 1:gray, 2:black
    int pre; //predecessor
    int dis; //distance
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

    void BFS(int s)
    {
        for(int i = 0; i < V; i++)
        {
            node[i].color = 0;
            node[i].pre = -1;
            node[i].dis = -1;
        }

        if(s > V) return;

        node[s].color = 1;
        node[s].pre = -1;
        node[s].dis = 0;

        queue<int> Q;
        list<int>::iterator i;

        Q.push(s);
        while(!Q.empty())
        {
            int tmp = Q.front();
            Q.pop();
            for(i = adj[tmp].begin(); i != adj[tmp].end(); i++)
            {
                if(node[*i].color == 0)
                {
                    Q.push(*i);
                    node[*i].color = 1;
                    node[*i].dis = node[tmp].dis + 1;
                    node[*i].pre = tmp;
                }
            }
            node[tmp].color = 2;
        }
    }

    void FindPath(int s, int v)
    {
        BFS(s);
        PrintPath(s, v);
    }

    void PrintPath(int s, int v)
    {
        if(v == s)
            cout << s << "\t";
        else if(node[v].pre == -1)
            cout << "Can not find a path" << endl;
        else
        {
            PrintPath(s, node[v].pre);
            cout << v << "\t";
        }
        cout << endl;
    }
};
int main()
{
    //build the graph
    Graph G = Graph(8);
    G.AddEdge(1,2);
    G.AddEdge(1,5);
    G.AddEdge(2,1);
    G.AddEdge(2,6);
    G.AddEdge(3,4);
    G.AddEdge(3,6);
    G.AddEdge(3,7);
    G.AddEdge(4,3);
    G.AddEdge(4,7);
    G.AddEdge(4,8);
    G.AddEdge(5,1);
    G.AddEdge(6,2);
    G.AddEdge(6,3);
    G.AddEdge(6,7);
    G.AddEdge(7,3);
    G.AddEdge(7,4);
    G.AddEdge(7,6);
    G.AddEdge(7,8);
    G.AddEdge(8,4);
    G.AddEdge(8,7);

    G.FindPath(2, 8);
    return 0;
}
