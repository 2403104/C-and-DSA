#include <bits/stdc++.h>
using namespace std;
int distinctSubsequence(string a, string b,int i, int j){
    if(j<0) return 1;
    if(i<0) return 0;
    if(a[i]==b[j]){
        return distinctSubsequence(a,b,i-1,j-1)+distinctSubsequence(a,b,i-1,j);
    }
    else return distinctSubsequence(a,b,i-1,j);
}
int distinctSubsequence2(string a, string b,int i, int j,vector<vector<int>>&dp){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]){
        return dp[i][j]= distinctSubsequence2(a,b,i-1,j-1,dp)+distinctSubsequence2(a,b,i-1,j,dp);
    }
    return dp[i][j]= distinctSubsequence2(a,b,i-1,j,dp);
}
int main(){
    string a, b;
    a="babgbag";
    b="bag";
    int n=a.length();
    int m=b.length();
    //dp[i][j] = Number of ways to form the first j characters of t from the first i characters of s
    
    //DP TABLE

    // vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    // for(int i=0;i<=n;i++){
    //     dp[i][0]=1;
    // }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
    //         else dp[i][j]=dp[i-1][j];
    //     }
    // }

    //DOUBLE 1D ARRAY
    // vector<int>prev(m+1,0),curr(m+1,0);
    // prev[0]=curr[0]=1;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         if(a[i-1]==b[j-1]) curr[j]=prev[j-1]+prev[j];
    //         else curr[j]=prev[j];
    //     }
    //     prev=curr;
    // }
    // cout<<prev[m];

    //SINGLE 1D ARRAY
    vector<int>dp(m+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
            if(a[i-1]==b[j-1]) dp[j]=dp[j-1]+dp[j];
        }
    }
    cout<<dp[m];

    return 0;
}