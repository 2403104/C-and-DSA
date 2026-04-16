#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[2]={NULL};
};
class Trie{
public:
    Node* root;
    Trie(){ 
        root=new Node();
    }

    void insert(int num){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bits=1 && (num>>i);
            if(node->links[bits]==NULL) node->links[bits]=new Node();
            node=node->links[bits];
        }
    }
public:
    int getMax(int num){
        Node* node=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit=1 && (num>>i);
            int checkBits=1-bit;
            if(node->links[checkBits]!=NULL){
                maxNum=maxNum | (1<<i);
                node=node->links[checkBits];
            }else{
                node=node->links[bit];
            }
        }
        return maxNum;
    }
};
//use of offline queries
vector<int> maxXorQueries(vector<int>&arr,vector<vector<int>>&queries){
    sort(arr.begin(),arr.end());
    vector<pair<int,pair<int,int>>> offline;
    int q=queries.size();
    for(int i=0;i<q;i++){
        offline.push_back({queries[i][i],{queries[i][0],i}});
    }
    sort(offline.begin(),offline.end());
    vector<int>ans(q,0);
    int idx=0;
    int n=arr.size();
    Trie trie;
    for(int i=0;i<q;i++){
        int ai=offline[i].first;
        int xi=offline[i].second.first;
        int qIdx=offline[i].second.second;
    }
}
int maxXor(vector<int>&arr1,vector<int>&arr2){
    Trie trie;
    int maxAns=0;
    for(auto it : arr1){
        trie.insert(it);
    }
    for(auto it : arr2){
        maxAns=max(maxAns,trie.getMax(it));
    }
    return maxAns;
}
int main(){
    vector<int> arr1 = {3, 10, 5, 25, 2, 8};
    vector<int> arr2 = {5, 25, 10, 2};
    cout << maxXor(arr1, arr2) << endl;    
    return 0;
}