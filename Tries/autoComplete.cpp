#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

class Trie
{
public:
    class Node
    {
    public:
        bool end;
        Node *next[26];
        Node()
        {
            end = false;
            for (int i = 0; i < 26; i++)
            {
                next[i] = NULL;
            }
        }
    };
    Node *root;
    Trie()
    {
        root = new Node();
    }
    void insert(string word)
    {
        Node *curr = root;
        for (char c : word)
        {
            int idx = c - 'a';
            if (curr->next[idx] == NULL)
            {
                curr->next[idx] = new Node();
            }
            curr = curr->next[idx];
        }
        curr->end = true;
    }
    void solve(Node* curr, vector<string>&ans,string pref){
        if(curr->end) ans.push_back(pref);
        for(int i=0;i<26;i++){
            if(curr->next[i]!=NULL){
                solve(curr->next[i],ans,pref+char('a'+i));
            }
        }

    }
    vector<string> autoComplete(string pref){
        Node* curr=root;
        for(char c : pref){
            int idx=c-'a';
            if(curr->next[idx]==NULL) return {};
            curr=curr->next[idx];
        }
        vector<string>ans;
        solve(curr,ans,pref);
        return ans; 
    }

};

int main()
{
    Trie trie;

    trie.insert("ankit");
    trie.insert("ankt");
    trie.insert("ankitkumar");
    trie.insert("ak");
    trie.insert("akumar");
    trie.insert("ankitkmr");

    vector<string>ans=trie.autoComplete("ak");
    for(auto i : ans) cout<<i<<"  ";
    return 0;
}