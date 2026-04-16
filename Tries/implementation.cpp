# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;

class Trie{
public:
    class Node{
    public:
        bool end;
        Node* next[26];
        Node(){
            end=false;
            for(int i=0;i<26;i++){
                next[i]=NULL;
            }
        }
    };
    Node* trie;
    Trie(){
        trie=new Node();
    }
    void insert(string word){
        int i=0;//tells us that at which character we are
        Node* it=trie;//help us to iterate trie
        while(i<word.size()){
            if(it->next[word[i]-'a']== NULL){
                it->next[word[i]-'a']=new Node();
            }
            it=it->next[word[i]-'a'];
            i++;
        }
            it->end=true;
    }
    bool search(string word){
        int i=0;
        Node* it=trie;
        while(i<word.size()){
            if(it->next[word[i]-'a']==NULL) return false;
            it=it->next[word[i]-'a'];
            i++;
        }
        return it->end;
    }
};

int main(){
    Trie *myTrie=new Trie();
    vector<string>word={"ankit","kumar","patel"};
    for(auto i : word){
        myTrie->insert(i);
    }
    if(myTrie->search("kumar")) cout<<"kumar found!!";
    else cout<<"kumar Not found!!";

    return 0;
}