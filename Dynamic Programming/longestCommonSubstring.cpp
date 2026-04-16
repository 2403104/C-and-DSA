#include <bits/stdc++.h>
using namespace std;
// int lcs(string a, string b){
//     int n=a.length();
//     int m=b.length();
//     vector<vector<int>>dp(n+1,vector<int>(m+1,0));
//     int ans=0;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=m;j++){
//             if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
//             else dp[i][j]=0;
//             ans=max(ans,dp[i][j]);
//         }
//     }
//     return ans;
// }
int lcs(string s1, string s2) {
    int a=s1.size();
    int b=s2.size();
    vector<int>prev(b+1,0),curr(b+1,0);
    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(s1[i-1]==s2[j-1]) curr[j]=1+prev[j-1];
            else curr[j]=max(curr[j-1],prev[j]);
        }
        prev=curr;
    }
    return prev[b];
}
int main(){
    //print lcs
    string a, b;
    a="kankiku";
    b="ankiu";
    // cout<<lcs(a,b);
    int n=a.size();
    int m=b.size();
    vector<vector<int>>dp1(n+1,vector<int>(m+1,0));
    vector<vector<string>>dp2(n+1,vector<string>(m+1,""));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]){
                dp1[i][j]=1+dp1[i-1][j-1];
                dp2[i][j]=dp2[i-1][j-1]+a[i-1];
            }
            else{
                dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1]);
                dp2[i][j]=(dp1[i-1][j]>dp1[i][j-1])?dp2[i-1][j]:dp2[i][j-1];
            }
        }
    }
    cout<<dp2[n][m]<<endl;
    return 0;
}
/*
  k a n k i k u
  0 0 0 0 0 0 0
a 0 1 0 0 0 0 0
n 0 0 2 0 0 0 0
k 0 0 0 3 0 1 0
i 0 0 0 0 4 0 0
u 0 0 0 0 0 4 4
*/