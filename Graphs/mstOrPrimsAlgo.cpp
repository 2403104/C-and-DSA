#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int spanningTree(int n, vector<vector<int>> adj[]) {
        using pii=pair<int,int>;
        priority_queue<pii,vector<pii>,greater<pii>>pq;//wt,node
        pq.push({0,0});
        vector<bool>vis(n,false);
        int mst=0;
        while(!pq.empty()){
            auto it=pq.top();
            int wt=it.first;
            int node=it.second;
            pq.pop();
            if(vis[node]) continue;
            mst+=wt;
            vis[node]=true;
            for(auto neb : adj[node]){
                int nod=neb[0];
                int w=neb[1];
                if(!vis[nod]) {
                    pq.push({w,nod});
                }
            }
        }
        return mst;
    }
};
int main(){

    return 0;
}