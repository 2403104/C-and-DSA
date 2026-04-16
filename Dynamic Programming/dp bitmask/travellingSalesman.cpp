#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define input(arr) for(auto &it : arr) cin>>it;
#define pb push_back
#define p push
#define F first
#define S second
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
vvi dp;
vvi dist;
int n;
int helper(int pos, int mask){
    if(mask==0) return dist[pos][0];
    if(dp[pos][mask]!=-1) return dp[pos][mask];
    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if(mask & (1<<i)){
            ans=min(ans,dist[pos][i]+helper(i,mask^(1<<i)));
        }
    }
    return dp[pos][mask]=ans;
}
void solve(){
    cin>>n;
    dist.resize(n,vi(n));
    rep(i,0,n){
        rep(j,0,n) cin>>dist[i][j];
    }
    int mask=(1<<(n));
    dp.resize(n,vi(mask,-1));
    cout<<helper(0,mask-1)<<endl;

}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr); 
    #endif

    solve();
    

    return 0;
}