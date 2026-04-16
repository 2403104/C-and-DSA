#include <bits/stdc++.h>
#define ll long long
using namespace std;
int helper(string &a, string &b,string &c, int i, int j,vector<vector<int>>&dp){
    if(i<0 && j<0) return 0;
    if(dp[i+1][j+1]!=-1) return dp[i+1][j+1];
    int idx=i+j+1;
    int ans=INT_MAX;
    if(i>=0 && a[i]==c[idx]) ans=min(ans,helper(a,b,c,i-1,j,dp));
    if(j>=0 && b[j]==c[idx]) ans=min(ans,helper(a,b,c,i,j-1,dp));
    if(i>=0 && a[i]!=c[idx]) ans=min(ans,helper(a,b,c,i-1,j,dp)+1);
    if(j>=0 && b[j]!=c[idx]) ans=min(ans,helper(a,b,c,i,j-1,dp)+1);
    return dp[i+1][j+1]=ans;
}
void solve(){
    string a,b,c;
    cin>>a>>b>>c;
    int n=a.length();
    int m=b.size();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<helper(a,b,c,n-1,m-1,dp)<<endl;
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}