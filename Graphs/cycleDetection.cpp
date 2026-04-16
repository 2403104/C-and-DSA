# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;
//USING BFS
bool bfs(int src, vector<int>adj[],int vis[]){
    vis[src]=1;
    queue<pair<int,int>>q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]= 1;
                q.push({it,node});
            }
            else if(parent!=it){
                return true;
            }
        }
    }
    return false;
}
bool isCycleBfs(int n , vector<int>arr[]){
    int vis[n]={0};
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(bfs(i,arr, vis )) return true;
        }
    }
    return false;
}

//USING DFS
bool dfs(int node, int parent ,int vis[],vector<int>adj[]){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            if(dfs(it,node,vis,adj)) return true;

        }else if(it!=node) return true;
    }
    return false;
}

bool isCycleDfs(int n, vector<int>adj[]){
    int vis[n]={0};
    return dfs(1,-1,vis,adj);
}

//cycle detection in directed graph using dfs
bool dfsCheck(int node, vector<int>adj[],vector<bool>&vis, vector<bool>&pathVis){
    vis[node]=true;
    pathVis[node]=true;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfsCheck(it, adj, vis, pathVis)) return true;
            //if the node has been already visited and it has to be visited on the same path
            else if(pathVis[it]) return true;
        }
    }
    pathVis[node]=false;
    return false;
}
bool isCyclic(int n, vector<int> adj[]){
    vector<bool>vis(n,false);
    vector<bool>pathVis(n,false);//for the same path
    for(int i=0;i<n;i++){
        if(!vis[i]){
            if(dfsCheck(i,adj,vis,pathVis)) return true;
        }
    }
    return false;
}
//cycle detection in directed graph using bfs
//if topological sort contains  less than n elements then ther is a cycle
bool bfsCheck(int n, vector<int>adj[]){
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto it : adj[i]){
            indegree[i]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0) q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cnt++;
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0) q.push(it);
        }
    }
    return cnt!=n;//if there is a cycle then we can't get all the element in the topological sort
}
//#SIMPLEST CODE
class Solution {
  public:
    bool dfs(int node, int fix, vector<vector<int>>&graph,vector<int>&vis){
        vis[node]=fix;
        for(auto it : graph[node]){
            if(vis[it]==-1){
                if(dfs(it,fix,graph,vis)) return true;
            }else if(vis[it]==fix) return true;
        }
        vis[node]=-1;
        return false;
    }
    bool isCyclic(int n, vector<vector<int>> &edges) {
        vector<vector<int>>graph(n);
        for(auto it : edges) graph[it[0]].push_back(it[1]);
        vector<int>vis(n,-1);
        for(int i=0;i<n;i++){
            if(vis[i]==-1) if(dfs(i,i,graph,vis)) return true;
        }
        return false;
    }
};

int main(){


    return 0;
}