# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;
void dfs(int node, vector<int>adj[],int vis[]){
    vis[node]=1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis);
        }
    }

}
int numOfProvince(vector<int>adj[],int n){
    int vis[n]={0};
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            cnt++;
            dfs(i,adj,vis);
        }
    }
    return cnt;
}

int main(){

    return 0;
}

