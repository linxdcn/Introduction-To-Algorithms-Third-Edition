#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

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

};
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

void MSTKruskal(Graph G)
{
    //generate the tree sets
    map<int, int> treeSet;
    for(int i = 0; i < G.V; i++)
        treeSet.insert(pair<int, int>(i, i));

    //sort all the edges
    vector<Edge> result;
    vector<Edge> allEdge;

    for(int i = 0; i < G.V; i++)
        for(int j = 0; j < i; j++)
            if(G.Adj[i][j] != 0)
                allEdge.push_back(Edge(i, j, G.Adj[i][j]));

    sort(allEdge.begin(), allEdge.end(), EdgeCompare);

    //find MST
    vector<Edge>::iterator iterEdge;
    map<int, int>::iterator iterTreeSet;
    for(iterEdge = allEdge.begin(); iterEdge != allEdge.end(); iterEdge++)
    {
        int node1 = iterEdge->s;
        int node2 = iterEdge->e;
        if(treeSet[node1] != treeSet[node2])
        {
            result.push_back(*iterEdge);
            int tmp = treeSet[node2];
            for(iterTreeSet = treeSet.begin(); iterTreeSet != treeSet.end(); iterTreeSet++)
                if(iterTreeSet->second == tmp)
                    iterTreeSet->second = treeSet[node1];
        }
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

    MSTKruskal(G);
    return 0;
}
