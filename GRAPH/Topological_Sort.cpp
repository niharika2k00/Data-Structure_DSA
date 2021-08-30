

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/* Topological sort:
    # The edges of the graph can be unidirectional/bidirectional.
    # TSort is only POSSIBLE  when the graph is Directed Acyclic Graph (DAG).
    # Requires a stack.
    # Run DFS on the graph and push each vertex in a stack after all its neighbours are visited.
      Pop each vertex from the stack and add it to a list to get the topologically sorted list of vertices.
    # 1st vertex in topological sorting is always a vertex with in-degree as 0 (a vertex with no incoming edges).
    # Linear orderring of Vertices i.e if there is an edge UV then U always comes before V.
    # Time complexity: O(V + E) | Space complexity: O(V)
*/

class Graph
{
public:
    int v;
    int index;
    // vector<string> Vertex = {"a", "b", "c", "d"};
    vector<vector<int>> adjacency_list; // declaration --  vector of vector

    Graph(int v)
    {
        index = 0;
        this->v = v;
        adjacency_list.resize(6);
    }

    void set_edge(int start, int end)
    {
        adjacency_list[start].push_back(end);
        cout << "start = " << start << "\tend = " << end << "\t value : " << adjacency_list[0][0] << "\n ";
    }

    void neighbours_show()
    {
        int k = adjacency_list[0][1];
        cout << "Node in list[0][1] : " << k << endl;
    }

    void dfsUtil(int start, vector<bool> &visited)
    {
        visited[start] = true;
        cout << "DFS Node in list : " << start /* << adjacency_list[start] */ << "\t";

        // for all the vertices adjacent(connected) to this vertex(i) ---------- means i th row traverse
        for (auto i = adjacency_list[start].begin(); i != adjacency_list[start].end(); ++i)
        {
            cout << "i = " << *i << endl;
            if (!visited[*i])
                dfsUtil(*i, visited);
        }
    }

    void DFS()
    {
        vector<bool> visited(adjacency_list.size(), false); // vector <bool> A(10,false) + memory allocate
        int i;
        for (i = 0; i < adjacency_list.size(); i++)
        {
            if (!visited[i])
                dfsUtil(i, visited);
        }
    }
};

int main()
{
    Graph g(6);
    cout << "\n**************************   Depth First Traversal  ************************\n";
    g.set_edge(0, 1);
    g.set_edge(0, 2);
    g.set_edge(1, 3);
    g.set_edge(1, 4);
    g.set_edge(2, 2);
    g.neighbours_show();

    cout << "\nFollowing is Depth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS();

    return 0;
}