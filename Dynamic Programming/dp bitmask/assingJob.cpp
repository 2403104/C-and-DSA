#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define input(arr,n) for(int index=0;index<n;index++) cin>>arr[index];
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
vvi cost;
int helper(int i, int mask, int& n){//assigning ith job to any jth person
    if(i==n) return 0;
    if(dp[i][mask]!=-1) return dp[i][mask];
    int ans=INT_MAX;
    for(int j =0;j<n;j++){
        if(mask & (1<<j)){
            ans=min(ans,cost[j][i]+helper(i+1,(mask^(1<<j)),n));
        }
    }
    return dp[i][mask] = ans;
}
void solve(){
    int n;
    cin>>n;
    cost.resize(n,vi(n));
    rep(i,0,n){
        input(cost[i],n);
    }
    int mask=1<<n;
    dp.resize(n+1,vi(mask,-1));
    cout<<helper(0,mask-1,n)<<endl;

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