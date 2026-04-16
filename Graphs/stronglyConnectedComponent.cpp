#include <bits/stdc++.h>
using namespace std;
/*
strongly connected components are only valid for directed graph
*/
void dfs(int node,vector<bool>&vis,vector<int>adj[],stack<int>&st){
    vis[node]=true;
    for(auto it : adj[node]){
        if(!vis[it]) dfs(it,vis,adj,st);
    }
    st.push(node);
}
void dfs(int node, vector<bool>&vis,vector<int>graph[]){
    vis[node]=true;
    for(auto it : graph[node]){
        if(!vis[it]) dfs(it,vis,graph);
    }    
}
int kosaraju(int n, vector<int>adj[]){
    //store according to its finishing time
    stack<int>st;
    vector<bool>vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,vis,adj,st);
        }
    }
    //reverse or transpose the graph
    vector<int>graph[n];
    for(int i=0;i<n;i++){
        vis[i]=false;//mark false again to reuse that again
        for(auto it : adj[i]){
            graph[it].push_back(i);
        }
    }
    int scc=0;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            scc++;
            dfs(node,vis,graph);
        }
    }
    return scc;
}
int main(){
 
    return 0;
}