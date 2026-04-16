#include <bits/stdc++.h>
using namespace std;
bool lowestCommonAncesstor(int node, vector<vector<int>>graph,int p,int q,vector<bool>&vis, int& ans){
    if(node==p || node==q) return true;
    bool left=false;
    bool right=false;
    vis[node]=true;
    int cnt=0;
    for(auto neb : graph[node]){
        if(vis[neb]) continue;
        bool curr=lowestCommonAncesstor(neb,graph,p,q,vis,ans);
        if(curr){
            cnt++;
            if(cnt==1) left=curr;
            else if(cnt==2) right=curr;
        }
    }
    vis[node]=false;
    if(left && right) {
        ans=node;
        return true;
    }
    return left || right;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr); 
    #endif
    int m,n;
    cin>>m>>n;
    vector<vector<int>>graph(n);
    for(int i=0;i<m;i++){
        int u, v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    int ans=-1;
    vector<bool>vis(n,false);
    int lowCA=lowestCommonAncesstor(0,graph,6,9,vis,ans);
    cout<<ans;


    return 0;
}
//           0
//         /   \
//        1     2
//       / \   / \
//      3   4 5   6
//     /     \ |    \
//    7       8 9    10
//LCA USING BINARY LIFTING
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<vector<int>>dp;
vector<int>depth;
void binaryLifting(int src,int par){
    dp[src][0]=par;
    for(int i=1;i<=20;i++){
        if(dp[src][i-1]!=-1){
            dp[src][i]=dp[dp[src][i-1]][i-1];
        }else{
            dp[src][i]=-1;
        }
    }
    for(auto child : graph[src]){
        if(child!=par){
            depth[child]=depth[src]+1;
            binaryLifting(child,src);
        }
    }
}
int liftToEqualHeight(int node, int k){
    for(int i=20;i>=0;i--){
        if(k>=(1<<i)){
            k-=(1<<i);
            node=dp[node][i];
        }
    }
    return node;
}
int lca(int u, int v){
    if(u==v) return u;
    int uDepth=depth[u],vDepth=depth[v];
    if (vDepth >uDepth) {
        swap(u,v);
        swap(uDepth ,vDepth);
    }
    u=liftToEqualHeight(u,uDepth-vDepth);

    for(int i=20;i>=0;i--){
        if(dp[u][i]!=dp[v][i]){
            u=dp[u][i];
            v=dp[v][i];
        }
    }
    return dp[u][0];

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr); 
    #endif
    
    int m,n;
    cin>>m>>n;
    graph.resize(n);
    depth.resize(n);
    dp.resize(n,vector<int>(21,-1));
    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[u].push_back(v);
    }
    int root=0;
    binaryLifting(root,-1);
    cin>>u>>v;
    cout<<"LCA = "<<lca(u,v);

    return 0;
}