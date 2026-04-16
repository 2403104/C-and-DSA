#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define nline cout <<'\n'
#define input(arr)       \
    for (auto &it : arr) \
        cin >> it;
#define output(arr)     \
    for (auto it : arr) \
        cout << it << " ";\
        cout<<endl;
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
ll solve(string &num,int n, int sum, bool tight,vector<vector<vector<int>>>&dp){
    if(sum<0) return 0;
    if(n==1){
        if(sum>=0 && sum<=9) return 1;
        return 0;
    }
    if(dp[n][sum][tight]!=-1) return dp[n][sum][tight];
    ll ans=0;
    ll ub=(tight?(num[num.size()-n]-'0'):9);
    for(int d=0;d<=ub;d++){
        ans+=solve(num,n-1,sum-d,(tight&(d==ub)),dp);
    }
    return dp[n][sum][tight]=ans;
}
void solve(){
    string k;
    int sum;
    cin>>k>>sum;
    vector<vvi>dp(k.size()+1,vvi(sum+1,vi(2,-1)));
    ll ans=solve(k,k.size(),sum,1,dp);
    cout<<ans<<endl;
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    solve();

    return 0;
}