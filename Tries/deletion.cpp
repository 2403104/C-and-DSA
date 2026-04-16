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
        int count;//for the counting of the word starting with prefix
        Node *next[26];
        Node()
        {
            end = false;
            count=0;
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
            curr->count++;
        }
        curr->end = true;
    }

    bool search(string word)
    {
        Node *curr = root;
        for (char c : word)
        {
            int idx = c - 'a';
            if (curr->next[idx] == NULL)
                return false;
            curr = curr->next[idx];
        }
        return curr->end;
    }
    bool  deleteHelper(string word, Node* curr, int depth){
        if(depth==word.size()){
            if(!curr->end) return false; //word not found     
            curr->end=false;
            for(int i=0;i<26;i++){
                if(curr->next[i]!=NULL) return false;//do not delete if children exists
            }
            return true;
        }
        int idx=word[depth]-'a';
        if(curr->next[idx]==NULL) return false;//word not found
        bool shouldDelete=deleteHelper(word,curr->next[idx],depth+1);
        if(shouldDelete){
            delete curr->next[idx];
            curr->next[idx]=NULL;
            if (curr->end) return false;  // Don't delete if it's the end of another word
            for(int i=0;i<26;i++){
                if(curr->next[i]!=NULL) return false;//do not delete if children exists
            }
            return true;
        }
        return false;
    }
    void remove(string word){
        deleteHelper(word,root, 0);
    }
    int countWordsWithPrefix(string pref){
        Node* it=root;
        for(char c : pref){
            int idx=c-'a';
            if(it->next[idx]==NULL) return 0;
            it=it->next[idx];
        }
        return it->count;
    }
};

int main()
{
    Trie trie;

    trie.insert("ankit");
    trie.insert("ankt");
    trie.insert("ankitkumar");
    trie.insert("ak");
    trie.insert("ankitkmr");

    cout << trie.countWordsWithPrefix("ak") << endl;
    return 0;
}