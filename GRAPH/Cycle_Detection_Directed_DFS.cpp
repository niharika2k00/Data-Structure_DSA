

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/* TOPOLOGICAL SORT :

   - Store the Vertex in the adjacency list
  -  [LOOP] Frequency calculate in inDegree vector
  -  [LOOP] Check if (inDegree[i] == 0)  ?  Queue.push(i)
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

    bool DFS_CycleCheck(int vertex, vector<int> &visited, vector<int> &dfsCycleVisited)
    {
        visited[vertex] = 1;
        dfsCycleVisited[vertex] = 1;

        for (auto it : adjacency_list[vertex]) // 1 -->  2 so dfs(2)
        // for (auto it = adjacency_list[vertex].begin(); it != adjacency_list[vertex].end(); ++it)
        {
            if (!visited[it])
            {
                if (DFS_CycleCheck(it, visited, dfsCycleVisited))
                    return true;
                else if (dfsCycleVisited[it])
                    return true;
            }
        }

        dfsCycleVisited[vertex] = 0;
        return false;
    }

    bool isCyclic()
    {
        int i, size = adjacency_list.size();
        vector<int> visited(size, 0), dfsCycleVisited(size, 0);

        for (i = 0; i < size; i++)
        {
            if (!visited[i])
                if (DFS_CycleCheck(i, visited, dfsCycleVisited))
                    return true;
        }
        return false;
    }
};

int main()
{
    Graph g(4); // total number of VERTEX in the graph
    cout << "\n**************************   Cycle Detection using BFS  ************************\n\n";

    // g.set_edge(0, 1);
    // g.set_edge(1, 2);
    // g.set_edge(2, 3);
    // g.set_edge(3, 1);

    g.set_edge(0, 1);
    g.set_edge(0, 2);
    g.set_edge(1, 2);
    g.set_edge(2, 0);
    g.set_edge(2, 3);
    g.set_edge(3, 3);

    bool isCyclic = g.isCyclic();
    cout << "isCyclic: " << isCyclic << endl;
    if (isCyclic)
        cout << "\n      CYCLE DETECTED          \n";
    else
        cout << "\n       NO CYCLE DETECTED       \n";

    return 0;
}