

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct createGraph
{
    int src;
    int dest;
    int weight;

    // Constructor
    createGraph(int start, int end, int wt)
    {
        src = start;
        dest = end;
        weight = wt;
    }
};

// BELLMAN FORD ALGORITM FUNCTION
void BellmanFord(vector<createGraph> &edgeList, int source, int totalVertex, int totalEdge)
{
    int i, j, u, v, cost, flag = 0;
    vector<int> dist(totalVertex, INT_MAX); // setting initial distances of the vertex is infinity
    dist[source] = 0;

    for (i = 0; i < totalVertex; i++) //  this loop runs for (n - 1) iteration [RULE]
    {
        for (j = 0; j < totalEdge; j++)
        {
            //  _____  if edgeList is vector of vector  _____
            // u = edgeList[j][0];
            // v = edgeList[j][1];
            // cost = edgeList[j][2];

            u = edgeList[j].src;
            v = edgeList[j].dest;
            cost = edgeList[j].weight;

            // -------   Relaxation   ----------
            int updatedDist = dist[u] + cost;
            if (updatedDist < dist[v])
                dist[v] = updatedDist;
        }
    }

    // for Checking negative cycles ---- Bellman not valid. [1 time traverse through all the edges]
    for (j = 0; j < totalEdge; j++)
    {
        u = edgeList[j].src;
        v = edgeList[j].dest;
        cost = edgeList[j].weight;

        int updatedDist = dist[u] + cost;
        if (updatedDist < dist[v])
        {
            cout << "Negative cycle found between vertex " << u << " and " << v << endl;
            flag = 1;
            break;
        }
    }

    if (!flag)
    {
        cout << "______  Bellman Ford Algorithm   _________\n";
        for (i = 0; i < totalEdge; i++)
            cout << i << "\t" << dist[i] << endl;
    }
}

int main()
{
    int tvertex = 4, tedge = 4;
    vector<createGraph> edgeList; // vector of structure

    // edgeList.push_back({1, 2, 4});   // ------> if vector of vector is used

    // start vertex(node) from 0
    //  vec.push_back(constructor());
    edgeList.push_back(createGraph(0, 1, 4));
    edgeList.push_back(createGraph(0, 3, 5));
    edgeList.push_back(createGraph(2, 1, -10));
    edgeList.push_back(createGraph(3, 2, 3));

    BellmanFord(edgeList, 0, tvertex, tedge);

    return 0;
}

/*
point mypoint = {0, 1};
a.push_back(mypoint);

   OR

 vec.push_back(constructor())
 */

/*
  EXPLAINATIONS ::

  1) Iterate (N - 1) times
  2) Valid for Negative Edges
  3) InValid for Negative Cycles
  4) Relaxation done (N - 1) times after that on Nth time while relaxation distance EILL NOT  modify , BUT
              if on Nth time further Relaxation takes place  then it has a NEGATIVE CYCLE.

 */