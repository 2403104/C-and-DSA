#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26]={NULL};
    bool flag=false;
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string s){
        Node* node=root;
        for(char ch :s){
            if(node->links[ch-'a']==NULL) {
                node->links[ch-'a']=new Node();
            }
            node=node->links[ch-'a'];
        }
        node->flag=true;
    }
    bool completeString(string s){
        Node* node=root;
        for(char ch : s){
            if(node->links[ch-'a']==NULL) return false;
            node=node->links[ch-'a'];
            if(node->flag==false) return false;
        }
        return true;
    }
    bool checkAllPrefExists(string s){
        Node* node=root;
        for(char ch : s){
            if(node->links[ch-'a']==NULL) return false;
            node=node->links[ch-'a'];
            if(!node->flag) return false;
        }
        return true;
    }
};
string completeString(vector<string>v,int n){
    Trie trie;
    for(auto it : v) trie.insert(it);
    string longest="";
    for(auto it : v){
        if(trie.checkAllPrefExists(it)){
            if(it.length()>longest.length()) longest=it;
            else if(it.length()==longest.length() && it>longest){
                 longest=it;
            }
        }
    }
    if(longest=="") return "";
    return longest;
}
int main(){

    return 0;
}