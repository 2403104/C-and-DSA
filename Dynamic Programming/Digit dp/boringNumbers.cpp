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
int dp[20][2];
ll solve(string &num , int n, int tight){
    if(n==num.size()) return 1;
    if(dp[n][tight]!=-1) return dp[n][tight];
    int ub=((tight)?num[n]-'0':9);
    int lb=(((n+1)%2!=0)?1:0);
    ll ans=0;
    for(int d=lb;d<=ub;d+=2){
        ans+=solve(num,n+1,(tight&(d==ub)));
    }
    return dp[n][tight]=ans;

}
void solve(){
    string l,r;
    cin>>l>>r;
    memset(dp,-1,sizeof(dp));
    ll ans=0;
    ans+=solve(r,0,1);
    memset(dp,-1,sizeof(dp));
    ans-=solve(l,0,1);
    bool left_ok=true;
    for(int i=0;i<l.size();i++){
        if((l[i]-'0')%2!=((i+1)%2)){
            left_ok=false;
            break;
        }
    }
    if(left_ok) ans+=1;
    // for(int i=0;i<20;i++){
    //     for(int j=0;j<2;j++) cout<<dp[i][j]<<" ";
    //     cout<<endl;
    // }
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