#include <bits/stdc++.h>
using namespace std;
int minCoins(vector<int>coins,int idx, int target){
    if(idx==0){
        if(target%coins[idx]==0) return target/coins[0];
        return 1e9;
    }
    int notTake=minCoins(coins, idx-1,target);
    int take=INT_MAX;
    if(coins[idx]<=target) take=1+minCoins(coins, idx, target-coins[idx]);
    return min(take, notTake);
}
int minCoins(vector<int>coins,int idx, int target,vector<vector<int>>&dp){
    if(dp[idx][target]!=-1) return dp[idx][target];
    if(idx==0){
        if(target%coins[idx]==0) return target/coins[0];
        return 1e9;
    }
    int notTake=minCoins(coins, idx-1,target);
    int take=INT_MAX;
    if(coins[idx]<=target) take=1+minCoins(coins, idx, target-coins[idx]);
    return dp[idx][target]=  min(take, notTake);
}
int main(){
    vector<int>arr={1,2,3};
    int target=7;
    int n=arr.size();
    // cout<<minCoins(arr,arr.size()-1,target);
    // vector<vector<int>> dp(n,vector<int>(target+1,-1));
    // cout<<minCoins(arr,arr.size()-1,target,dp);
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int tar = 0; tar <= target; tar++) {
        if (tar % arr[0] == 0) {
            dp[0][tar] = tar / arr[0];
        } else {
            dp[0][tar] = INT_MAX - 1;
        }
    }
    
    for (int i = 1; i < n; i++) {
        for (int tar = 0; tar <= target; tar++) {
            int notTake = dp[i - 1][tar];
            int take = INT_MAX - 1;
            if (arr[i] <= tar && dp[i][tar - arr[i]] != INT_MAX - 1) {
                take = 1 + dp[i][tar - arr[i]];
            }
            dp[i][tar] = min(notTake, take);
        }
    }
    
    if (dp[n - 1][target] >= INT_MAX - 1) {
        cout << -1;
    } else {
        cout << dp[n - 1][target];
    }    

    return 0;
}