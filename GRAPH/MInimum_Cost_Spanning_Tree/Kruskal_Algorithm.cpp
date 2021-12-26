
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

bool comp(createGraph a, createGraph b)
{
    return a.weight < b.weight;
}

int Find(int src, vector<int> &parent)
{
    if (src == parent[src])
        return src;
    return Find(parent[src], parent);
}

void Union(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int rootX = Find(x, parent);
    int rootY = Find(y, parent);

    if (rank[rootX] < rank[rootY])
        parent[rootX] = rootY;

    else if (rank[rootX] > rank[rootY])
        parent[rootY] = rootX;

    // When both have same AbsoluteRoot
    else
    {
        parent[rootX] = rootY;
        rank[rootY]++;
    }
}

void Kruskal_Algorithm(vector<createGraph> &edgeList, int n)
{
    vector<int> parent(n);
    vector<int> rank(n, 0);
    vector<pair<int, int>> mst;
    int cost = 0, i;

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (auto it : edgeList)
    {
        if (Find(it.src, parent) != Find(it.dest, parent))
        {
            cost = cost + it.weight;
            mst.push_back({it.src, it.dest});
            Union(it.src, it.dest, parent, rank);
        }
    }

    cout << cost << endl;
    for (auto it : mst)
        cout << it.first << " - " << it.second << endl;
}

int main()
{
    int n = 4; // Nodes
    vector<createGraph> edgeList;
    edgeList.push_back(createGraph(0, 1, 4));
    edgeList.push_back(createGraph(0, 3, 8));
    edgeList.push_back(createGraph(2, 1, 11));
    edgeList.push_back(createGraph(3, 2, 3));

    sort(edgeList.begin(), edgeList.end(), comp); //  sort acc to weight
    Kruskal_Algorithm(edgeList, n);

    return 0;
}
