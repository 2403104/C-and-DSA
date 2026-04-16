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
    void insert(string word){
        Node* node=root;//dummy variable of root
        for(int i=0;i<word.size();i++){
            if(node->links[word[i]-'a']==NULL){
                node->links[word[i]-'a']=new Node();
            }
            node=node->links[word[i]-'a'];
        }
        node->flag=true;
    }
    bool search(string word){
        Node* node=root;
        for(char ch : word){
            if(node->links[ch-'a']==NULL) return false;
            node=node->links[ch-'a'];
        }
        return node->flag==true;
    }
    bool startsWith(string pref){
        Node* node=root;
        for(char ch : pref){
            if(node->links[ch-'a']==NULL) return false;
            node=node->links[ch-'a'];
        }
        return true ;
    }
    void insert(string word){
        
    }
};
int main(){

    return 0;
}