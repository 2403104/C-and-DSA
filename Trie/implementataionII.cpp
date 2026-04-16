#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26]={NULL};
    int ew=0;//end with
    int cp=0;//count prefix
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node* node=root;
        for(char ch : word){
            if(node->links[ch-'a']==NULL){
                node->links[ch-'a']=new Node();
            }
            node->cp++;
        }
        node->ew++;
    }
    int countEndsWith(string s){
        Node* node=root;
        for(char ch : s){
            if(node->links[ch-'a']==NULL) return 0;
            node=node->links[ch-'a'];
        }
        return node->ew;
    }
    int countStartsWith(string s){
        Node* node=root;
        for(char ch :s){
            if(node->links[ch-'a']==NULL) return 0;
            node=node->links[ch-'a'];
        }
        return node->cp;
    }
    bool search(string s){
        Node* node=root;
        for(char ch : s){
            if(node->links[ch-'a']==NULL) return false;
            node=node->links[ch-'a'];
        }
        return node->ew!=0;
    }
    void erase(string s){
        if(!search(s)) return;
        Node* node=root;
        for(char ch : s){
            node->cp--;
            node=node->links[ch-'a'];
        }
        node->ew--;
    }
};
int main(){

    return 0;
}