

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/* Topological sort:
    # The edges of the graph can be unidirectional/bidirectional   ---->  DIRECTED GRAPH REQUIRED
    # TSort is only POSSIBLE  when the graph is Directed Acyclic Graph (DAG).
    # Requires a STACK.
    # Run DFS on the graph and push each vertex in a stack after all its neighbours are visited.
      Pop each vertex from the stack and add it to a list to get the topologically sorted list of vertices.
    # 1st vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).
    # Linear orderring of Vertices i.e if there is an edge U --> V then U always comes before V.

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

    void DFS(int start, vector<bool> &visited, stack<int> &Stack)
    {
        visited[start] = true;

        for (auto i = adjacency_list[start].begin(); i != adjacency_list[start].end(); ++i)
            if (!visited[*i])
                DFS(*i, visited, Stack);

        Stack.push(start);
    }

    void topological_Sort()
    {
        vector<bool> visited(adjacency_list.size(), false); // vector <bool> A(10,false) + memory allocate
        stack<int> Stack;
        vector<int> topoDisplay;

        for (int i = 0; i < adjacency_list.size(); i++)
        {
            if (!visited[i]) //  not visited
                DFS(i, visited, Stack);
        }

        // At the end when all the vertices are visited, Print the STACK
        while (!Stack.empty())
        {
            cout << Stack.top() << "\t";
            Stack.pop();
        }

        visited.clear();
        cout << "\n\n";
    }
};

int main()
{
    Graph g(6);
    cout << "\n**************************   Topological Sort using DFS  ************************\n\n";

    g.set_edge(2, 3);
    g.set_edge(3, 1);
    g.set_edge(4, 0);
    g.set_edge(4, 1);
    g.set_edge(5, 0);
    g.set_edge(5, 2);

    g.topological_Sort();

    return 0;
}