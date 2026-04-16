#include <bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(int n, vector<vector<int>> adj)
{
    vector<int> indeg(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
            indeg[it]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adj[node])
        {
            indeg[it]--;
            if (indeg[it] == 0)
                q.push(it);
        }
    }
    return ans;
}
vector<char> alienDict(int n, int k, vector<string> &dict)
{
    vector<vector<int>> adj(k);
    for (int i = 1; i < n; i++)
    {
        string first = dict[i - 1];
        string second = dict[i];
        int s1 = first.size(), s2 = second.size();
        int mini = min(s1, s2);
        for (int j = 0; j < mini; j++)
        {
            if (first[j] != second[j])
            {
                int c1 = first[j] - 'a';
                int c2 = second[j] - 'a';
                adj[c1].push_back(c2);
                break;
            }
        }
    }
    vector<int> topo = topologicalSort(k, adj);
    vector<char> ans;
    for (auto it : topo)
    {
        ans.push_back(it + 'a');
    }
    return ans;
}
int main()
{
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    vector<char> ans = alienDict(5, 4, dict);
    for (char ch : ans)
        cout << ch << ' ';

    return 0;
}