#include <bits/stdc++.h>
using namespace std;
vector<int> Adj[1001];

struct Union_Find
{
    vector<int> iParent;
    Union_Find(int n)
    {
        iParent = vector<int>(n);
        for (int i = 0; i < n; ++i)
        {
            iParent[i] = i;
        }
    }
    // toan tu Find va Union
    int Find(int x)
    {
        if (iParent[x] == x)
        {
            return x;
        }
        else
        {
            iParent[x] = Find(iParent[x]); // Nen parent
            return iParent[x];
        }
    }

    void Union(int x, int y)
    {
        iParent[Find(x)] = Find(y);
    }
};