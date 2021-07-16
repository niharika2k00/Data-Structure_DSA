

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

struct createGraph
{
    int src;
    int dest;
    int weight;

    // constructor
    createGraph(int start, int end, int wt)
    {
        src = start;
        dest = end;
        weight = wt;
    }
};

// point mypoint = {0, 1};
// a.push_back(mypoint);

// Or if you're allowed, give point a constructor, so that you can use a temporary:

// a.push_back(point(0,1));

// BELLMAN FORD ALGORITM FUNCTION
vector<int> BellmanFord(vector<createGraph> &edgeList, int source, int vertex_total, int edge_total)
{
}

int main()
{
    int tvertex = 4, tedge = 4;
    vector<createGraph> edgeList;

    // edgeList.push_back({1, 2, 4});
    edgeList.push_back(createGraph(1, 2, 4));
    edgeList.push_back(createGraph(1, 4, 5));
    edgeList.push_back(createGraph(3, 2, -10));
    edgeList.push_back(createGraph(4, 3, 3));

    vector<int> distance = BellmanFord(edgeList, 0, tvertex, tedge);

    return 0;
}