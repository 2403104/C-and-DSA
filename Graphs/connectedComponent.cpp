#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define rep(i, a, b) for (int i = a; i < b; i++)
vector<vector<int>>adj;
vector<int>component;
vector<bool>vis;
int getComp(int idx){
    if(vis[idx]) return 0;
    vis[idx]=1;
    int ans=1;
    for(auto i : adj[idx]){
        if(!vis[i]){
             ans++;
             vis[i]=true;
        }
    }
    return ans;
}
int main() {
    int n, m;//n= no of edges
    cin >> n >> m;

    ;
    adj=vector<vector<int>>(n);
    vis=vector<bool>(n,0);  

    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for(int i=0;i<n;i++){
        if(!vis[i]){
            component.push_back(getComp(i));
        }
    }
    return 0;
}
