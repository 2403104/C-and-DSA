#include <bits/stdc++.h>
using namespace std;
//find the longest common subsequence
int lcs1(string a , string b, int idx1, int idx2){
    if(idx1<0 || idx2<0 ) return 0;
    if(a[idx1]==b[idx2]) return 1+lcs1(a,b, idx1-1,idx2-1);
    return max(lcs1(a,b, idx1-1,idx2),lcs1(a,b,idx1,idx2-1));
}

int lcs2(string a , string b, int idx1, int idx2,vector<vector<int>>&dp){
    if(idx1<0 || idx2<0 ) return 0;
    if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    if(a[idx1]==b[idx2]) return dp[idx1][idx2]= 1+lcs2(a,b, idx1-1,idx2-1,dp);
    return  dp[idx1][idx2]= max(lcs2(a,b, idx1-1,idx2,dp),lcs2(a,b,idx1,idx2-1,dp));
}


int main(){
    // string a="ankiku";
    // string b="ankumar";
    string a, b;
    cin>>a>>b;
    int n=a.length();
    int m=b.length();
    vector<vector<int>>dp1(n+1,vector<int>(m+1,-1));
    vector<vector<string>>dp2(n+1,vector<string>(m+1));
    for(int i=0;i<=m;i++){
        dp1[0][i]=0;
        dp2[0][i]="";
    }
    for(int j=0;j<=n;j++){
        dp1[j][0]=0;
        dp2[j][0]="";
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) {
                dp1[i][j]=1+dp1[i-1][j-1];
                dp2[i][j]=dp2[i-1][j-1]+a[i-1];
            }
            else {
                int store=max(dp1[i-1][j],dp1[i][j-1]);
                if(store==dp1[i-1][j]) dp2[i][j]=dp2[i-1][j];
                else dp2[i][j]=dp2[i][j-1];
                dp1[i][j]=store;
            }
        }
    }
    for(auto i : dp2){
        for(auto j :i) cout<<j<<" ";
        cout<<endl;
    }
    cout<<dp1[n][m]<<endl;
    cout<<dp2[n][m]<<endl;
    return 0;
}