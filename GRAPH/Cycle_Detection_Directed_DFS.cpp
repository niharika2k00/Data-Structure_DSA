

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

    bool DFS_CycleCheck(int vertex, vector<bool> &visited, vector<bool> &dfsCycleVisited)
    {
        visited[vertex] = true;
        dfsCycleVisited[vertex] = true;

        for (auto it : adjacency_list[vertex]) // 1 -->  2 so dfs(2)
        {
            if (!visited[it] && DFS_CycleCheck(it, visited, dfsCycleVisited))
                return true;
            else if (dfsCycleVisited[it])
                return true;
        }

        dfsCycleVisited[vertex] = false;
        return false;
    }

    bool isCyclic()
    {
        int i, len = adjacency_list.size();
        vector<bool> visited(len, false), dfsCycleVisited(len, false);
        for (i = 0; i < len; i++)
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

    // EX - 1
    // g.set_edge(0, 1);
    // g.set_edge(1, 2);
    // g.set_edge(2, 3);
    // g.set_edge(3, 1);

    // EX - 2
    g.set_edge(0, 1);
    g.set_edge(0, 2);
    g.set_edge(1, 2);
    g.set_edge(2, 0);
    g.set_edge(2, 3);
    g.set_edge(3, 3);

    bool isCyclic = g.isCyclic();
    cout << "isCyclic: " << isCyclic << endl;
    if (isCyclic)
        cout << "\n      CYCLE DETECTED          \n\n";
    else
        cout << "\n       NO CYCLE DETECTED       \n\n";

    return 0;
}