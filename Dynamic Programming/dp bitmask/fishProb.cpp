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
vector<vector<double>>prob;
vector<double>dp;
vector<double>probSum;
int n;
double pMove(int prevMask, int fish){//fish has to die
    int k=__builtin_popcount(prevMask);
    ll deno=k*(k-1)/2;
    double curr=0;
    for(int f=0;f<n;f++){
        if((1<<f)&prevMask){
            curr+=prob[f][fish];
        }
    }
    return curr/(1.0*deno);
}
double helper(int mask){
    int alive=__builtin_popcount(mask);
    if(alive==n) return 1;
    if(dp[mask]>-0.9) return dp[mask];
    double ans=0;
    for(int fish=0;fish<n;fish++){
        if(!(mask & (1<<fish))){
            int prevMask=mask | (1<<fish);
            double prevDay=helper(prevMask);
            ans+=prevDay*pMove(prevMask,fish);
        }
    }
    return dp[mask]=ans;

}
void solve(){
    cin>>n;
    prob.resize(n,vector<double>(n));
    rep(i,0,n){
        rep(j,0,n){
            cin>>prob[i][j];
        }
    }
    
    dp.assign(1<<n,-1.0);
    int totalMask=(1<<n);
    cout<<fixed<<setprecision(6);
    rep(i,0,n){
        cout<<helper(1<<i)<<' ';
    }
    cout<<endl;
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