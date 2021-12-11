
#include <iostream>
#include <vector>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

// graph(Destination , Cost);
// queue(Cost ,Destination )

// Print  queue
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
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue; // min-heap ; In pair => (dist,from)
    vector<int> distance(n + 1, INT_MAX);                                                  // 1-indexed array for calculating shortest paths (set initially infinite);

    distance[source] = 0;
    queue.push(make_pair(0, source)); // (distance , vertex)  --> in MinHeap the lowest distance will be on TOP

    while (!queue.empty())
    {
        int dist = queue.top().first;
        int curVtx = queue.top().second;
        cout << " Cost = " << dist << " Current Vertex = " << curVtx << endl;

        queue.pop();

        for (auto it = graph[curVtx].begin(); it != graph[curVtx].end(); it++) //  adjacency list traversal
        {
            int destVtx = it->first;
            int cost = it->second;
            cout << " Destination Vertex = " << destVtx << " Cost = " << cost << endl;

            if (distance[destVtx] > distance[curVtx] + cost) // Relaxation takes place
            {
                distance[destVtx] = distance[curVtx] + cost; // Stores the MINIMUM dist
                queue.push(make_pair(distance[destVtx], destVtx));
            }
        }

        ShowQueue(queue);
    }

    cout << "\n *************    Dijkstra's  Algorithm  starting Node " << source << " :   ****************\n";
    for (int i = 1; i <= n; i++)
        cout << distance[i] << "\t";
}

int main()
{
    int n = 4;
    vector<pair<int, int>> graph[n + 1]; // 2D Array of pairs

    // 1-indexed adjacency list for of graph
    // graph[src].push_back(make_pair(dest , cost));

    graph[1].push_back(make_pair(4, 8));
    graph[1].push_back(make_pair(2, 4));
    graph[3].push_back(make_pair(2, 1));
    graph[4].push_back(make_pair(3, 8));

    //    ----------    FOR USER INPUT  Adjacent List   ------------
    /* int vertex, edge, a, b, cost; // vertex, edge, from (source) , to (destination)  , cost
    cin >> vertex >> edge;
    for (int i = 0; i < vertex; i++)
    {
        cin >> a >> b >> cost;
        graph[a].push_back(make_pair(b, cost));
        graph[b].push_back(make_pair(a, cost));
    } */

    Dijkstra(graph, 1, n);

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