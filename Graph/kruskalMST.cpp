#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
pair<long long, pair<int, int>> p[MAX];
class UnionFind
{
public:
    vector<int> parent;
    vector<int> size;
    int n;
    // 当前连通分量数目
    int setCount;

public:
    UnionFind(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int findset(int x)
    {
        return parent[x] == x ? x : parent[x] = findset(parent[x]);
    }

    bool unite(int x, int y)
    {
        x = findset(x);
        y = findset(y);
        if (x == y)
        {
            return false;
        }
        if (size[x] < size[y])
        {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }

    bool connected(int x, int y)
    {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

long long Kruskal()
{
    UnionFind un(nodes + 1);
    long long mincost = 0;
    for (int i = 0; i < edges; ++i)
    {
        int x = p[i].second.first;
        int y = p[i].second.second;
        int w = p[i].first;
        if (un.unite(x, y))
        {
            mincost += w;
        }
    }
    return mincost;
}

int main()
{
    int x, y;
    long long weight, cost, minimumCost;
    cin >> nodes >> edges;
    for (int i = 0; i < edges; ++i)
    {
        cin >> x >> y >> weight;
        p[i] = make_pair(weight, make_pair(x, y));
    }
    // Sort the edges in the ascending order
    sort(p, p + edges);
    minimumCost = Kruskal();
    cout << minimumCost << endl;
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <utility>
// #include <algorithm>
// #include <numeric>
// using namespace std;
// const int MAX = 1e4 + 5;
// int id[MAX], nodes, edges;
// pair<long long, pair<int, int>> p[MAX];
// class UnionFind
// {
// public:
//     vector<int> parent;
//     vector<int> size;
//     int n;
//     // 当前连通分量数目
//     int setCount;

// public:
//     UnionFind(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1)
//     {
//         iota(parent.begin(), parent.end(), 0);
//     }

//     int findset(int x)
//     {
//         return parent[x] == x ? x : parent[x] = findset(parent[x]);
//     }

//     bool unite(int x, int y)
//     {
//         x = findset(x);
//         y = findset(y);
//         if (x == y)
//         {
//             return false;
//         }
//         if (size[x] < size[y])
//         {
//             swap(x, y);
//         }
//         parent[y] = x;
//         size[x] += size[y];
//         --setCount;
//         return true;
//     }

//     bool connected(int x, int y)
//     {
//         x = findset(x);
//         y = findset(y);
//         return x == y;
//     }
// };

// void initialize()
// {
//     cout << nodes;
//     for (int i = 0; i < nodes; ++i)
//         id[i] = i;
// }

// int root(int x)
// {
//     while (id[x] != x)
//     {
//         id[x] = id[id[x]];
//         x = id[x];
//     }
//     return x;
// }

// void union1(int x, int y)
// {
//     int p = root(x);
//     int q = root(y);
//     id[p] = id[q];
// }

// long long kruskal(pair<long long, pair<int, int>> p[])
// {
//     UnionFind un(nodes);
//     int x, y;
//     long long cost, minimumCost = 0;
//     for (int i = 0; i < edges; ++i)
//     {
//         // Selecting edges one by one in increasing order from the beginning
//         x = p[i].second.first;
//         y = p[i].second.second;
//         cost = p[i].first;
//         // Check if the selected edge is creating a cycle or not
//         if (un.findset(x) != un.findset(y))
//         {
//             minimumCost += cost;
//             bool eeeee = un.unite(x, y);
//         }
//     }
//     return minimumCost;
// }

// int main()
// {
//     int x, y;
//     long long weight, cost, minimumCost;

//     cin >> nodes >> edges;
//     // initialize();
//     for (int i = 0; i < edges; ++i)
//     {
//         cin >> x >> y >> weight;
//         p[i] = make_pair(weight, make_pair(x, y));
//     }
//     // Sort the edges in the ascending order
//     sort(p, p + edges);
//     minimumCost = kruskal(p);
//     cout << minimumCost << endl;
//     return 0;
// }