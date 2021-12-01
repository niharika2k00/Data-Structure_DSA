
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    //  push back in both the vector as they are UNDIRECTED GRAPH
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    for (int i = 0; i < V; ++i)
    {
        cout << " | " << i << " | ";
        for (auto x : adj[i]) // traversing on a single list[row]
            cout << "-> " << x;
        printf("\n");
    }
}

int main()
{
    int V = 5, i;
    vector<int> adj[V]; // array of arrays (vector of vectors) --- static fixed size
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    cout << "\n **************  Adjacency list of vertex   ************* \n";
    printGraph(adj, V);

    cout << "\n\n";
    for (auto x : adj[1]) // traversing on a single list[row]
        cout << "-> " << x;

    return 0;
}