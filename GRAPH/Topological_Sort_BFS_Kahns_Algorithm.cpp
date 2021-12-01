

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/* TOPOLOGICAL SORT :

   - Store the Vertex in the adjacency list
  -  [LOOP] Frequency calculate in inDegree vector
  -  [LOOP] Check if (inDegree[i] == 0)  ?  Queue.push(i)        // CONDITION
  -  [LOOP] FOR BFS ----->

    # Time complexity: O(V + E) | Space complexity: O(V) for Stack
*/

class Graph
{
public:
    int index;
    vector<vector<int>> adjacency_list; // declaration --> Vecotr of Vector means 2D vector

    Graph(int size)
    {
        index = 0;
        adjacency_list.resize(size);
    }

    void set_edge(int start, int end)
    {
        adjacency_list[start].push_back(end);
    }

    void topological_Sort_BFS()
    {
        int size = adjacency_list.size(); // total Vertex
        vector<int> inDegree(size, 0);    //  Number of edges directed to it (Node)
        vector<int> topoDisplay;
        queue<int> Q;
        int i, vertex;

        for (i = 0; i < size; i++)
            for (auto it : adjacency_list[i])
                inDegree[it]++;

        for (i = 0; i < size; i++)
            if (inDegree[i] == 0)
                Q.push(i);

        while (!Q.empty())
        {
            vertex = Q.front();
            Q.pop();
            cout << "Vertex popped from queue : " << vertex << "\n";
            topoDisplay.push_back(vertex);

            // for (auto it = adjacency_list[vertex].begin(); it != adjacency_list[vertex].end(); ++it)
            for (auto it : adjacency_list[vertex])
            {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    Q.push(it);
            }
        }

        // DISPLAY ALL THE ELEMENTS IN THE GRAPH
        cout << "\n";
        for (auto it : topoDisplay)
            cout << it << "\t";

        inDegree.clear();
        cout << "\n\n";
    }
};

int main()
{
    Graph g(6); // total number of VERTEX in the graph
    cout << "\n**************************   Topological Sort using BFS  ************************\n\n";

    g.set_edge(2, 3);
    g.set_edge(3, 1);
    g.set_edge(4, 0);
    g.set_edge(4, 1);
    g.set_edge(5, 0);
    g.set_edge(5, 2);

    g.topological_Sort_BFS();

    return 0;
}