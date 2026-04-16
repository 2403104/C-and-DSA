#include<bits/stdc++.h>
using namespace std;

bool isBipartiteByBfs(int n , vector<int>adj[]){
    queue<int>q;
    q.push(0);//assuming the graph is connected
    int color[n];
    for(int i=0;i<n;i++){
        color[i]=-1;
    }
    color[0]=0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(int it:adj[node]){
            if(color[it]==-1){
                color[it]=!color[node];
                q.push(it);

            }else if (color[it]==color[node]){
                return false;
            }
        }
    }
    return true;
}


bool isBipartiteByBfs(int n, vector<int> adj[]) {
    vector<int> color(n, -1);
    
    for (int i = 0; i < n; i++) {  //Loop over all nodes for disconnected graphs
        if (color[i] == -1) {  // Start BFS only if the node is unvisited
            queue<int> q;
            q.push(i);
            color[i] = 0;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int it : adj[node]) {
                    if (color[it] == -1) {
                        color[it] = !color[node];
                        q.push(it);
                    } else if (color[it] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}
 
bool dfs(int node, int col, int color[],vector<int>adj[]){
    color[node]=col;
    for(auto it:adj[node]){
        if(color[it]==-1){
            return dfs(it,!col,color, adj);
        }
        else if(color[it]==col) return false;
    }
    return true;
}
bool isBipartiteByDfs(int n,vector<int>adj[]){
    int color[n]={-1};
    for(int i=0;i<n;i++){//assuming both connected disconnected and connected graph
        if(color[i]==-1){
            if(dfs(i,0,color, adj))  return true;
        }
    }
    return false;
}
int main(){

    return 0;
}