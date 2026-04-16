#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
      int n;
      int solve(vector<int>&coins,int sum, int idx,vector<vector<int>>&dp){
          // if(sum==0) return 0;
          if(idx==0){
              if(sum%coins[idx]==0) return sum/coins[idx];
              return 1e7;
          }
          if(dp[idx][sum]!=-1) return dp[idx][sum];
          int notTake=solve(coins,sum,idx-1,dp);
          int take=INT_MAX;
          if(sum>=coins[idx]){
              take=1+solve(coins,sum-coins[idx],idx,dp);
          }
          return dp[idx][sum]= min(take,notTake);
      }
      int minCoins(vector<int> &coins, int target) {
          n=coins.size();
          // vector<vector<int>>dp(n,vector<int>(sum+1,-1));
          // int ans= solve(coins,sum,n-1,dp);
          // if(ans==1e7) return -1;
          vector<vector<int>>dp(n,vector<int>(target+1,0));
          for(int tar=0;tar<=target;tar++){
              if(tar%coins[0]==0) dp[0][tar]=tar/coins[0];
              else dp[0][tar]=1e7;
          }
          for(int i=1;i<n;i++){
              for(int tar=0;tar<=target;tar++){
                  int notTake=dp[i-1][tar];
                  int take=1e7;
                  if(tar>=coins[i]){
                      take=1+dp[i][tar-coins[i]];
                  }
                  dp[i][tar]=min(take,notTake);
              }
          }
          int ans=dp[n-1][target];
          return (ans==1e7)?-1:ans;
      }
  };
int main(){

    return 0;
}