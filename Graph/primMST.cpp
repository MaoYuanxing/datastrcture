#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;
const int MAX = 1e4 + 1;
typedef pair<long long, int> PII;
bool marked[MAX];
vector<PII> adj[MAX];

int prim(int x)
{
    priority_queue<PII, vector<PII>, greater<PII>> Q;
    Q.push(make_pair(0, x));
    int mincost = 0;
    while (!Q.empty())
    {
        auto tmp = Q.top();
        Q.pop();
        int y = tmp.second;
        if (marked[y])
            continue;
        marked[y] = true;
        mincost += tmp.first;
        for (int i = 0; i < adj[y].size(); ++i)
        {
            if (!marked[adj[y][i].second])
            {
                Q.push(adj[y][i]);
            }
        }
    }
    return mincost;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }
    cout << prim(1);
}

// leetcode 模板感觉也可以很好的体现prim的思想
class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size(); // point is represents by (x,y);
        int mincost = 0;
        auto dist = [&](vector<int> &a, vector<int> &b) -> int
        {
            return abs(a[0] - b[0]) + abs(a[1] - b[1]);
        };
        vector<bool> visited(n, 0);
        visited[0] = 1;
        int mann = INT_MAX;
        vector<int> minw(n, 0);
        for (int i = 1; i < n; ++i)
        {
            minw[i] = dist(points[0], points[i]);
        }

        for (int k = 0; k < n - 1; ++k)
        {
            int pos = 0;
            int mann = INT_MAX;
            for (int i = 0; i < n; ++i)
            {
                if (!visited[i] && mann > minw[i])
                {
                    mann = minw[i];
                    pos = i;
                }
            }
            visited[pos] = 1;
            mincost += mann;
            minw[pos] = 0;
            for (int i = 0; i < n; ++i)
            {
                if (!visited[i] && dist(points[pos], points[i]) < minw[i])
                {
                    minw[i] = dist(points[pos], points[i]);
                }
            }
        }
        return mincost;
    }
};