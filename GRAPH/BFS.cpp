#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
public:
    int v;
    int index;
    // vector<string> Vertex = {"a", "b", "c", "d"};
    vector<vector<int>> adjacency_list; // declaration --> Vecotr of Vector means 2D vector dynamic

    // CONSTRUCTOR
    Graph(int v)
    {
        index = 0;
        this->v = v;
        adjacency_list.resize(v);
    }

    /*   void vertexInsert()
    {
        printf("--- Vertex of %d Nodes ---\n", v);
        for (auto i : Vertex)
            cout << i << " ";
    }

    void search(string x, string y)
    {
        int start, end, i;
        for (i = 0; i < Vertex.size(); i++)
        {
            if (x == Vertex[i])
                start = i;
            else if (y == Vertex[i])
                end = i;
        }
        set_edge(start, end);
    } */

    void set_edge(int start, int end)
    {
        // cout << "set_edge running ";
        adjacency_list[start].push_back(end);
        cout << "start = " << start << "\tend = " << end << "\t value : " << adjacency_list[0][0] << "\n ";
    }

    void neighbours_show()
    {
        int k = adjacency_list[0][1];
        cout << "Node in list[0][1] : " << k << endl;
    }

    void BFS(int vertex)
    {
        queue<int> Q;
        // cout << adjacency_list.size();
        // vector<int> visited(adjacency_list.size()) = {0};  // vector <int> A (10) = {0}
        vector<bool> visited(adjacency_list.size(), false); // vector <bool> A(10,false) + memory allocate

        if (!visited[vertex]) // not visited the vertex(VERTEX)
        {
            Q.push(vertex);
            visited[vertex] = true;
        }

        while (!Q.empty())
        {
            // Dequeue a vertex from queue and print it
            vertex = Q.front();
            cout << "Vertex popped from queue : " << vertex << "\n";
            Q.pop();

            // 1st : traversing the list of 2(2--> 0,3)
            for (auto i = adjacency_list[vertex].begin(); i != adjacency_list[vertex].end(); ++i)
            // for (auto it : adjacency_list[vertex])
            {
                cout << "i = " << *i << endl;
                if (!visited[*i]) //  (!true)
                {
                    visited[*i] = true;
                    Q.push(*i);
                }
            }
        }
    }
};

int main()
{
    Graph g(4);
    cout << "\n**************************   Breath First Traversal  ************************\n";
    // g.vertexInsert();

    g.set_edge(0, 1); // DIRECTED edge
    g.set_edge(0, 2);
    g.set_edge(1, 3);
    g.set_edge(2, 0);
    g.set_edge(2, 3);
    g.set_edge(3, 3);
    g.neighbours_show();

    cout << "\nFollowing is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}

// Note : We are taking 0 ZERO indexing vector , where the 1st vertex is 0.  +   Directed Graph.

/*
        Time Complexity

     * While () loop runs V times (total no of verices as each vertices enqueue/dequeue 1 times)
     * Inner Loop runs E times (adjacent edges)


 */