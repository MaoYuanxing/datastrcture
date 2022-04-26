#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;

/*
Input
The first line contains n (1 ≤ n ≤ 200000) — the number of vertices in the graph.

The second line contains n integers a1, a2, ..., an (0 ≤ ai < 2^30) — the numbers assigned to the vertices.

Output
Print one number — the weight of the minimum spanning tree in the graph.

*/

#define maxn 200010
#define maxb 31
#define maxnodes (maxn * maxb)

#define UNDEF -1
#define ROOT 0

struct TrieNode
{
    int node[2];
    int l, r;
} T[maxnodes];

int TrieNodes;

void Init()
{
    memset(T, UNDEF, sizeof(T));
    TrieNodes = 1;
}

int a[maxn];

int GetTrieNode()
{
    return TrieNodes++;
}

void TrieInsert(int x, int idx)
{ // void TrieInsert(int x, int idx)
    //代表将 x = a[idx]按照从高到低位插入到字典树中，idx代表排序后数组a的下标；
    int now = ROOT;
    for (int i = maxb - 1; i >= 0; --i)
    {
        int bit = ((x >> i) & 1);
        if (T[now].node[bit] == UNDEF)
        {
            T[now].node[bit] = GetTrieNode();
        }

        if (T[now].l == UNDEF)
        {
            T[now].l = idx;
        }
        T[now].r = idx;
        now = T[now].node[bit];
    }
}

//查询就是给定 一棵子树 和 一个值 x xx，要求在 给定子树 上找到和 x xx 异或最小的值；
long long TrieQurey(int x, int depth, int now)
{
    long long ret = 0;
    for (int i = depth; i >= 0; --i)
    {
        int bit = ((x >> i) & 1);
        if (T[now].node[bit] != UNDEF)
        {
            now = T[now].node[bit];
        }
        else
        {
            now = T[now].node[bit ^ 1];
            ret += 1 << i;
        }
    }
    return ret;
}

long long Boruvka(int now, int depth)
{
    if (now == UNDEF)
    {
        return 0;
    }

    long long l = Boruvka(T[now].node[0], depth - 1);
    long long r = Boruvka(T[now].node[1], depth - 1);
    long long ans = l + r;
    if (T[now].node[0] != UNDEF && T[now].node[1] != UNDEF)
    {
        int x = T[now].node[0], y = T[now].node[1];
        long long ret = 1e9;
        ret *= ret;
        for (int i = T[x].l; i <= T[x].r; ++i)
        {
            ret = min(ret, TrieQurey(a[i], depth - 1, y) + (1 << depth));
        }
        ans += ret;
    }
    return ans;
}

int main()
{
    Init();
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        TrieInsert(a[i], i);
    }

    cout << Boruvka(ROOT, 30) << endl;
}