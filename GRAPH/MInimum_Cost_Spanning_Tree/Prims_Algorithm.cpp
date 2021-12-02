
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

void Dijkstra(vector<pair<int, int>> graph[], int source, int n)
{
    // priority_queue <Type, vector<Type>, ComparisonType > min_heap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue;
    vector<int> distance(n + 1, INT_MAX);

    cout << "The distances from source, " << source << ", are : \n";
    for (int i = 1; i <= n; i++)
        cout << distance[i] << "\t";
}

int main()
{
    int n = 4;
    vector<pair<int, int>> graph[n + 1];

    graph[1].push_back(make_pair(4, 8));
    graph[1].push_back(make_pair(2, 4));
    graph[3].push_back(make_pair(2, 1));
    graph[4].push_back(make_pair(3, 8));

    Prims(graph, 1, n);
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