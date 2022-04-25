#include <bits/stdc++.h>

class Solution
{
    vector<vector<string>> res;
    vector<string> path;
    bool onediff(const string &a, const string &b)
    {
        int n = a.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i])
                count++;
        }
        return count == (n - 1);
    }
    unordered_map<string, vector<string>> graph(const vector<string> &wordList)
    {
        int n = wordList.size();
        unordered_map<string, vector<string>> res;
        for (int i = 0; i < n; ++i)
        {

            for (int j = 0; j < n; ++j)
            {
                if (onediff(wordList[i], wordList[j]))
                {
                    res[wordList[i]].push_back(wordList[j]);
                }
            }
        }
        return res;
    }

    void getShortestPath(unordered_map<string, vector<string>> G, const string &b, const string &e)
    {

        int level = ShortestPath(G, b, e);
        // unordered_set<string> visited;
        path.push_back(b);
        help(G, e, level, visited);
    }

    int ShortestPath(unordered_map<string, vector<string>> &G, const string &b, const string &e)
    {
        int level = 1;
        queue<string> Q;
        Q.push(b);
        while (!Q.empty())
        {
            int size = Q.size();
            level++;
            for (int i = 0; i < size; ++i)
            {
                string tmp = Q.front();
                Q.pop();

                for (string s : G[tmp])
                {
                    if (s == e)
                        return level;
                    Q.push(s);
                }
            }
        }
        return level;
    }

    void help(unordered_map<string, vector<string>> &G, const string &e, int i, )
    {

        if (i == 1 && path.back() == e)
        {
            res.push_back(path);
            return;
        }
        if (i <= 1)
            return;

        for (auto a : G[path.back()])
        {
            path.push_back(a);
            help(G, e, i - 1);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        int flag = 0;

        for (string s : wordList)
        {
            if (s == endWord)
            {
                flag = 1;
                break;
            }
        }

        if (!flag)
            return {};
        wordList.push_back(beginWord);
        unordered_map<string, vector<string>> graphic = graph(wordList);

        getShortestPath(graphic, beginWord, endWord);
        return res;
    }
};

int main()
{
    string b = "a", e = "c";
    vector<string> word = {"a", "b", "c"};
}