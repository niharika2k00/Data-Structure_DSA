
#include <iostream>
#include <vector>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

// prototype
// void Dijkstra(vector<pair<int, int>> &graph, int source, int n);

void Dijkstra(vector<pair<int, int>> *graph, int source, int n)
{

    cout << source;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap ; In pair => (dist,from)
    vector<int> distance(n + 1, INT_MAX);                                               // 1-indexed array for calculating shortest paths;

    distance[source] = 0;
    pq.push(make_pair(0, source)); // (dist,from)

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        vector<pair<int, int>>::iterator it;
        for (it = graph[prev].begin(); it != graph[prev].end(); it++)
        {
            int next = it->first;
            int nextDist = it->second;
            if (distance[next] > distance[prev] + nextDist)
            {
                distance[next] = distance[prev] + nextDist;
                pq.push(make_pair(distance[next], next));
            }
        }
    }

    cout << "The distances from source, " << source << ", are : \n";
    for (int i = 1; i <= n; i++)
        cout << distance[i] << " ";
    cout << "\n";
}

int main()
{
    int n = 4;
    vector<pair<int, int>> graph[n + 1]; // size

    // 1-indexed adjacency list for of graph
    // graph[src].push_back(make_pair(dest , cost));

    graph[1].push_back(make_pair(4, 8));
    graph[1].push_back(make_pair(2, 4));
    graph[3].push_back(make_pair(2, 1));
    graph[4].push_back(make_pair(3, 8));

    Dijkstra(graph, 1, n);
    return 0;
}