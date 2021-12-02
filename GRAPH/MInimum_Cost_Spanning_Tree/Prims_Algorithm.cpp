
#include <iostream>
#include <vector>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

void ShowQueue(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue = Q;
    while (!Q.empty())
    {
        cout << '\t' << Q.top().first << ' ' << Q.top().second << endl;
        Q.pop();
    }
}

void Prims(vector<pair<int, int>> adjList[], int source, int n)
{
    // priority_queue <Type, vector<Type>, ComparisonType > min_heap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    vector<int> edgeWeight(n, INT_MAX);
    vector<int> parent(n, -1);
    vector<bool> mst(n, false);

    edgeWeight[0] = 0;
    queue.push({0, 0});

    while (!queue.empty())
    {
        int node = queue.top().second;
        queue.pop();

        mst[node] = true;

        for (auto it = adjList[node].begin(); it != adjList[node].end(); it++)
        {
            int dest = it->first;
            int cost = it->second;

            if (mst[dest] == false && cost < edgeWeight[dest])
            {
                edgeWeight[dest] = cost;
                parent[dest] = node;
                queue.push({edgeWeight[dest], dest});
            }
        }
    }

    cout << "\n *************    Prim's Minimum Spanning Tree (MST) | Greedy Algorithm   ****************\n";
    for (int i = 1; i < n; i++)
        cout << parent[i] << " -> " << i << " \n";
}

int main()
{
    int n = 5;
    vector<pair<int, int>> adjList[n];

    // Undirected Graph          0  --->   (1 , 2)   ===   source  --->   (destination  ,  cost)
    adjList[0].push_back(make_pair(1, 2));
    adjList[0].push_back(make_pair(3, 6));
    adjList[1].push_back(make_pair(3, 8));
    adjList[1].push_back(make_pair(4, 5));
    adjList[1].push_back(make_pair(2, 3));
    adjList[2].push_back(make_pair(4, 7));

    Prims(adjList, 0, n);

    return 0;
}

/*
EXPLAINATIONS ::

        1)  Set the adjacency list  graph[src].push_back(make_pair(dest , cost))
        2)  Create MIN_HEAP  &  distance vector ( to store the cost )
        3)  Initialise the Index 1 with cost 0
        4)   While (!Queue.empty()){

                      Queue.top()  extract                     //  Queue (Cost , Vertex) as all operation is done on queue ->  first
                      traverse the adjacencyList with this vertex
                      Relaxation - and store the minimum distance

        5) when the distance[cost] array is Set then traverse it

 */