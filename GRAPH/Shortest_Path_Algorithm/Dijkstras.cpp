
#include <iostream>
#include <vector>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

// graph(Vertexconnected , dist);
// queue(dist ,Vertexconnected )

void Dijkstra(vector<pair<int, int>> graph[], int source, int n)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> queue; // min-heap ; In pair => (dist,from)
    vector<int> distance(n + 1, INT_MAX);                                                  // 1-indexed array for calculating shortest paths (set initially infinite);

    distance[source] = 0;
    queue.push(make_pair(0, source)); // (weight , vertex)  --> as during minHeap the lowest distance will come on TOP

    while (!queue.empty())
    {
        int neighbourDist = queue.top().first;
        int neighbourVertex = queue.top().second;
        cout << " Vertex = " << neighbourVertex << " Cost = " << neighbourDist << endl;

        queue.pop();

        vector<pair<int, int>>::iterator it;
        for (it = graph[neighbourVertex].begin(); it != graph[neighbourVertex].end(); it++) //  adjacency list traversal
        {
            int currVertex = it->first;
            int currVertexCost = it->second;
            cout << " currVertex = " << currVertex << " nxtDIST = " << currVertexCost << endl;

            if (distance[currVertex] > distance[neighbourVertex] + currVertexCost) // Relaxation takes place
            {
                distance[currVertex] = distance[neighbourVertex] + currVertexCost; // Stores the MINIMUM dist
                queue.push(make_pair(distance[currVertex], currVertex));
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
    vector<pair<int, int>> graph[n + 1];

    // 1-indexed adjacency list for of graph
    // graph[src].push_back(make_pair(dest , cost));

    graph[1].push_back(make_pair(4, 8));
    graph[1].push_back(make_pair(2, 4));
    graph[3].push_back(make_pair(2, 1));
    graph[4].push_back(make_pair(3, 8));

    /* 
    //    ----------  for user input Adjacent List  ------------
    int vertex, edge, a, b, cost; // vertex, edge, from (source) , to (destination)  , cost
    cin >> vertex >> edge;
    for (int i = 0; i < vertex; i++)
    {
        cin >> a >> b >> cost;
        graph[a].push_back(make_pair(b, cost));
        graph[b].push_back(make_pair(a, cost));
    } 
    */

    Dijkstra(graph, 1, n);
    return 0;
}

/* 
EXPLAINATIONS :: 
 
        1)  Set the adjacency list  graph[src].push_back(make_pair(dest , cost))
        2)  Create MIN_HEAP &  distance vector ( to store the cost )
        3)   Initialise the Index 1 with cost 0
        4)   while (!Queue.empty()){

                      Queue.top()  extract                     //  Queue (Cost , Vertex)
                      traverse the adjacencyList with this vertex
                      Relaxation - and store the minimum distance

        5) when the distance[cost] array is Set then traverse it              
        
 */