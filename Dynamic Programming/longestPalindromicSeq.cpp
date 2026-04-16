#include <bits/stdc++.h>
using namespace std;
int lps(string s,int left, int right){
    if (left > right) return 0;
    if (left == right) return 1;
    int n=s.length();
    int ans=0;
    if(s[left]==s[right]) ans+=2+lps(s,left+1,right-1);
    else ans+=1+max(lps(s,left+1,right),lps(s,left,right-1));
    return ans;
}
int lps2(string s){
    int n=s.length();
    string rev=s;
    reverse(rev.begin(),rev.end());
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
        dp[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==rev[j-1]) dp[i][j]=1+dp[i-1][j-1];
        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
    }
    return dp[n][n];
}
//minimum insertion to palindrome
int minIsertions(string s){
    return (s.length()-lps2(s));
}
//minimum insertions or deletions to convert string a to string b
int minInsertDelete(string a, string b){
    
}

int main(){
    string s="abbsa";
    int n=s.length();
    cout<<minIsertions(s)<<endl;
    cout<<lps2(s)<<endl;
    return 0;
}