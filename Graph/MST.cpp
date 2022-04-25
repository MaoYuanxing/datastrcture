#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    explicit UnionFind(int n) : p_(n), r_(n) { iota(begin(p_), end(p_), 0); } // e.g. p[i] = i
    int Find(int x) { return p_[x] == x ? x : p_[x] = Find(p_[x]); }
    bool Union(int x, int y)
    {
        int rx = Find(x);
        int ry = Find(y);
        if (rx == ry)
            return false;
        if (r_[rx] == r_[ry])
        {
            p_[rx] = ry;
            ++r_[ry];
        }
        else if (r_[rx] > r_[ry])
        {
            p_[ry] = rx;
        }
        else
        {
            p_[rx] = ry;
        }
        return true;
    }

private:
    vector<int> p_, r_;
};

class Solution
{

    int kruskal(vector<vector<int>> &edges, int exclude, int in, int n)
    {
        UnionFind un(n);
        int mincost = 0;
        int count = 0;
        if (in > 0)
        {
            mincost += edges[in][2];
            un.Union(edges[in][0], edges[in][1]);
            count++;
        }
        for (int i = 0; i < edges.size(); ++i)
        {
            if (i == exclude)
                continue;
            if (!un.Union(edges[i][0], edges[i][1]))
                continue;
            mincost += edges[i][2];
            count++;
        }
        return count == n - 1 ? mincost : INT_MAX;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {

        for (int i = 0; i < edges.size(); ++i)
            edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](vector<int> a, vector<int> b) -> bool
             { return a[2] < b[2]; });
        vector<int> c, ps;
        int min = kruskal(edges, -1, -1, n);
        cout << min << " ";
        for (int i = 0; i < edges.size(); ++i)
        {

            if (min < kruskal(edges, i, -1, n))
                c.push_back(edges[i][3]);
            else if (min == kruskal(edges, -1, i, n))
                ps.push_back(edges[i][3]);
        }

        return {c, ps};
    }
};

int main()
{
    int n = 5;
    vector<vector<int>> edges = {{0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2}, {0, 4, 3}, {3, 4, 3}, {1, 4, 6}};
    Solution A;
    A.findCriticalAndPseudoCriticalEdges(n, edges);
    return 0;
}