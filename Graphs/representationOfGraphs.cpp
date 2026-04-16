# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;

#define vi vector<int>;
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define ff first
#define ss second
const int N=1e5+2,MOD=1e9+7;

vector<int>adj[N];

int main(){
    //ADJACENCY MATRIX

    // int n,m;//n=nodes,m=no of  edges
    // cin>>n>>m;
    // vector<vector<int>> adj(n+1,vector<int>(n+1,0));//this is different one
    // rep(i,0,m)
    // {
    //     int x, y;
    //     cin>>x>>y;
    //     adj[x][y]=1;
    //     adj[y][x]=1;
    // }

    // cout<<"Adjacency Matrix is given by : "<<endl;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout<<adj[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //ADJACENCY LIST
    
    int n,m;
    cin>>n>>m;

    rep(i,0,m)
    {
        int x,y;
        cin>>x>>y;

        adj[x].push_back(y);
        adj[y].push_back(x);

    }

    cout<<"Adjacency list of above is :"<<endl;
    rep(i,1,n+1){
        cout<<i<<" -> ";
        for(int x: adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }

    return 0;
}

// 7 7
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 2 7
// 3 7