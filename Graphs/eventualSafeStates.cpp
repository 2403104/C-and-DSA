#include <bits/stdc++.h>
using namespace std;
vector<int> eventualSafeNodes(int n, vector<int> adj[]){
    vector<vector<int>>adj(n);
    vector<int> indeg(n,0);
    for(int i=0;i<n;i++){
        for(auto it :  adj[i]){
            adj[it].push_back(i);
            indeg[i]++;
        }
    }
    queue<int>q;
    vector<int>safeNodes;
    for(int i=0;i<n;i++){
        if(indeg[i]==0) q.push(i);
    }
    while(!q.empty()){
        int node=q.front();
        q.pop();
        safeNodes.push_back(node);
        for(auto it : adj[node]){
            indeg[it]--;
            if(indeg[it]==0) q.push(it);
        }
    }
    sort(safeNodes.begin(),safeNodes.end());
    return safeNodes;
}
int main(){

    return 0;
}