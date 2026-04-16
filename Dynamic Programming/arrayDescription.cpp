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
bool valid(int n,int m){
    return n<=m && n>=1;
}
void solve(){
    int n,m;cin>>n>>m;
    vi arr(n);
    input(arr);
    vvi dp(n+1,vi(m+1,0));
    for(int i=1;i<=n;i++){
        if(arr[i]==0 || arr[i]==i) dp[1][i]=1;
    }
    for(int i=2;i<=n;i++){
        for(int k=1;k<=m;k++){
            if(arr[i-1]!=0 && arr[i-1]!=k) {
                dp[i][k]=0;
                continue;
            }
            for(int bod=k-1;bod<=k+1;bod++){
                if(!valid(bod,m)) continue;
                dp[i][k]=(dp[i][k]+dp[i-1][bod])%MOD;;
            }
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++){
        ans=(ans+dp[n][i])%MOD;
    }
    cout<<ans<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     freopen("error.txt", "w", stderr);
// #endif

    solve();

    return 0;
}