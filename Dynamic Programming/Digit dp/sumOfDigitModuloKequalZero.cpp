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
string k;
int sum;
ll dp[10001][100][2];
ll solve(int n, int mod, bool tight){
    if(n==k.size()) return mod==0?1:0;
    if(dp[n][mod][tight]!=-1) return dp[n][mod][tight];
    ll ans=0;
    ll ub=(tight?(k[n]-'0'):9);
    for(int d=0;d<=ub;d++){
        ans=(ans+solve(n+1,(mod+d)%sum,(tight&(d==ub))))%MOD;
    }
    return dp[n][mod][tight]=ans;
}
void solve(){
    cin>>k>>sum;
    memset(dp,-1,sizeof(dp));
    ll ans=solve(0,0,1);
    cout<<(ans-1+MOD)%MOD<<endl;
    
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