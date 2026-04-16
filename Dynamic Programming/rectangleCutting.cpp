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
void solve(){
    int n,m;
    cin>>n>>m;
    vvi dp(n+1,vi(m+1,1e9));
    //dp[i][j] is the minimum number of cuts required to cut into squares
    for(int i=0;i<=min(m,n);i++) dp[i][i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==j) continue;
            for(int w=1;w<=i-1;w++){
                dp[i][j]=min(dp[i][j],dp[w][j]+dp[i-w][j]+1);
            }
            for(int h=1;h<=j-1;h++){
                dp[i][j]=min(dp[i][j],dp[i][h]+dp[i][j-h]+1);
            }
        }
    }
    cout<<dp[n][m]<<endl;
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