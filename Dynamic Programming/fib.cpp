# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;

int fib(int n,vector<int>&dp){
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
    // return dp[n]=fib(n-1,dp)+fib(n-1,dp);//both are same
}

int main(){
    int n;
    cin>>n;
    // vector<int>dp(n+1,-1);
    // cout<<fib(n,dp);
    vector<int>dp(n+1,0);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n];


    return 0;
}