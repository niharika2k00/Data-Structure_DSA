
#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

// TIME COMPLEXITY ==> O(V + E)

class Graph
{
public:
    int v;
    int index;
    vector<vector<int>> adjacency_list; // declaration --> Vecotr of Vector means 2D vector

    Graph(int v)
    {
        index = 0;
        this->v = v;
        adjacency_list.resize(6);
    }

    void set_edge(int start, int end)
    {
        adjacency_list[start].push_back(end);
        cout << "\n"
             << start << " -->  " << end << " ";
    }

    void neighbours_show()
    {
        int k = adjacency_list[0][1];
        cout << "\nNode in list[0][1] : " << k << endl;
    }

    void dfsUtil(int start, vector<bool> &visited)
    {
        visited[start] = true;
        cout << "DFS Node in list : " << start << "\t";
        // for all the vertices adjacent(connected) to this vertex(i) ----------   means i th row traverse
        for (auto i = adjacency_list[start].begin(); i != adjacency_list[start].end(); ++i)
        {
            cout << "\n";
            if (!visited[*i])
                dfsUtil(*i, visited);
        }
    }

    void DFS()
    {
        vector<bool> visited(adjacency_list.size(), false); // vector <bool> A(10,false) + memory allocate
        for (int i = 0; i < adjacency_list.size(); i++)
        {
            if (!visited[i]) //  Not Visited
                dfsUtil(i, visited);
        }
    }
};

int main()
{
    Graph g(5);
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