#include <bits/stdc++.h>
using namespace std;
void topoSort(int node, vector<pair<int,int>>adj[],vector<bool>&vis,stack<int>&st){
    vis[node]=true;
    for(auto it : adj[node]){
        if(!vis[it.first]) topoSort(it.first,adj,vis,st);
    }
    st.push(node);
}
vector<int>shortestPath(int n , int m , vector<int>edges[]){
    vector<pair<int,int>>adj[n];
    for(int i=0;i<n;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int wt=edges[i][2];
        adj[u].push_back({v,wt});
    }
    vector<bool>vis(n,false);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            topoSort(i,adj,vis,st);
        }
    }
    vector<int>dist(n,1e8);
    dist[0]=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
    }

}
int main(){

    return 0;
}