#include <bits/stdc++.h>
using namespace std;
vector<int> printShortestPath(int n, int m, vector<vector<int>>&edges){//vector<{node1,node2,weight}>
    vector<pair<int,int>>adj[n+1];
    for(auto it : edges){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;//{distance, node}
    vector<int>dis(n+1,1e9),parent(n+1,0);
    for(int i=1;i<=n;i++) parent[i]=i;
    dis[1]=0;
/*
rank and size //not efficinet
unite 
*/
    pq.push({0,1});
    while(!pq.empty()){
        auto it=pq.top();
        int distance=it.first;
        int node=it.second;
        pq.pop();
        for(auto i : adj[node]){
            int nextNode=i.first;
            int edgeWeight=i.second;
            if(distance+edgeWeight<dis[nextNode]){
                dis[nextNode]=distance+edgeWeight;
                pq.push({dis[nextNode],nextNode});
                parent[nextNode]=node;
            }
        }
    }
    if(dis[n]==1e9) return {-1};
    vector<int>path;
    int node=n;
    while(parent[node]!=node){
        path.push_back(node);
        node=parent[node];
    }
    path.push_back(1);
    reverse(path.begin(),path.end());
    return path;

}
int main(){
    
    int n = 7, m = 10;
    vector<vector<int>> edges = {
        {4, 6, 5},
        {1, 3, 4},
        {5, 6, 2},
        {2, 4, 7},
        {1, 2, 2},
        {3, 5, 3},
        {6, 7, 4},
        {2, 3, 1},
        {4, 5, 6},
        {3, 4, 3}
    };
    vector<int> path = printShortestPath(n, m, edges);
    if (path[0] == -1) {
        cout << "No path exists." << endl;
    } else {
        cout << "Shortest path: ";
        for (auto node : path) {
            cout << node << "->";
        }
        cout << endl;
    }
    
    return 0;
}