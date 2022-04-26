#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    vector<TrieNode *> lettermap;
    bool endOfword;
    TrieNode(bool _e = false) : endOfword(_e)
    {
        lettermap = vector<TrieNode *>(26);
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    };
    void insert(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int j = word[i] - 'a';
            if (curr->lettermap[j] == nullptr)
            {
                TrieNode *node = new TrieNode();
                curr->lettermap[j] = node;
            }
            curr = curr->lettermap[j];
        }
        curr->endOfword = true;
    }

    bool search(string word)
    {
        TrieNode *curr = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int j = word[i] - 'a';
            if (curr->lettermap[j] == nullptr)
                return false;
            curr = curr->lettermap[j];
        }
        return curr->endOfword;
    }
};

class Solution
{

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        Trie tr;
        for (string s : wordDict)
        {
            tr.insert(s);
        }
        while (!s.empty())
        {

            int end = 0;
            for (int i = s.size(); i > 0; --i)
            {
                if (tr.search(s.substr(0, i)))
                {
                    end = i;
                    s = s.substr(i, s.size() - i);
                }
            }
            if (!end)
                break;
        }
        return s.empty();
    }
};

int main()
{
    string s = "applepenapple";
    vector<string> wordList = {"apple", "pen"};
    Solution A;
    if (A.wordBreak(s, wordList))
    {
        cout << "successfully...." << endl;
    }
}