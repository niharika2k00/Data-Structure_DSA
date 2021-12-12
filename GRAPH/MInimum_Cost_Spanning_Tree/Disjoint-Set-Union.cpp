
#include <iostream>
using namespace std;

class DisjointSet
{
    int *rank, *parent, n;

public:
    // Constructor to create and Initialize sets of n items
    DisjointSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }

    void makeSet()
    {
        int i;
        for (i = 0; i < n; i++)
            parent[i] = i;
    }

    int Find(int x)
    {
        if (x == parent[x]) //  when X is absolute root
            return x;
        return Find(parent[x]);
    }

    void Union(int x, int y)
    {
        int absRootX, absRootY;
        absRootX = Find(x);
        absRootY = Find(y);

        if (absRootX == absRootY) //  Belongs to the same set
            return;

        if (rank[absRootX] < rank[absRootY])
            parent[absRootX] = absRootY;

        else if (rank[absRootX] > rank[absRootY])
            parent[absRootY] = absRootX;

        else
        {
            parent[absRootY] = absRootX;
            cout << "rank[absRootX] = " << rank[absRootX] << endl;
            // rank[absRootX] = rank[absRootX] + 1;
            rank[absRootX]++;
        }
    }
};

int main()
{
    DisjointSet obj(5);
    obj.Union(0, 2);
    obj.Union(4, 2);
    obj.Union(3, 1);

    if (obj.Find(4) == obj.Find(0))
        cout << "Yes\n";
    else
        cout << "No\n";

    if (obj.Find(1) == obj.Find(0))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
