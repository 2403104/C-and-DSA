#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26]={NULL};
};
int countSubstring(string s){
    int cnt=0;
    Node* root=new Node();
    int n=s.length();
    for(int i=0;i<n;i++){
        Node* node=root;
        for(char ch : s.substr(i)){
            if(node->links[ch-'a']==NULL) {
                node->links[ch-'a']=new Node();
                cnt++;
            }
            node=node->links[ch-'a'];
        }
    }
    return cnt++;
}

int main(){
    string s="abab";
    cout<<countSubstring(s);
    return 0;
}