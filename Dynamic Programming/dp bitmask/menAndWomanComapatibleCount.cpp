#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define input(arr)       \
    for (auto &it : arr) \
        cin >> it;
#define output(arr)        \
    for (auto it : arr)    \
        cout << it << " "; \
    cout << endl;
#define pb push_back
#define p push
#define F first
typedef std::vector<int> vi;
typedef std::vector<long long> vl;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
const int MOD=1e9+7;
int dp[22][1<<22];
int arr[22][22];
int helper(int i, int mask, int &n){
    if(i==n) return __builtin_popcount(mask)==n;
    if(dp[i][mask]!=-1) return dp[i][mask];
    int ans=0;
    for(int j=0;j<n;j++){
        if((mask>>j)&1 || arr[i][j]==0) continue;
        else {
            int curr=helper(i+1,(mask | (1<<j)),n);
            ans=(ans+curr)%MOD;
        }
    }
    return dp[i][mask]=ans;
}
void solve(){
    int n;
    cin>>n;
    memset(dp,-1,sizeof(dp));
    memset(arr,-1,sizeof(arr));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }
    int ans=helper(0,0,n);
    cout<<ans<<endl;
    

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}