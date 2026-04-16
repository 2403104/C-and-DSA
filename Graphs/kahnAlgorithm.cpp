#include <bits/stdc++.h>
using namespace std;
vector<int> topologicalSort(int n, vector<int>adj[]){
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    //there will always be a element whose indegree is 0 in a graph for sure
    vector<int>topo;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: adj[node]){
            indegree[it]--;
            if(indegree[it]==0){
                q.push(it);
            }
        }
    }
    return topo;
}
int main(){

    return 0;
}
