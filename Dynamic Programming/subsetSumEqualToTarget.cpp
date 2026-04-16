#include <bits/stdc++.h>
using namespace std;
bool targetSum(int idx, int target , vector<int>arr){
    if(target==0 ) return true;
    if(idx==0) return arr[0]==target;
    bool notTaken=targetSum(idx-1,target, arr);
    bool taken=false;
    if(target>=arr[idx]){
        taken=targetSum(idx-1,target-arr[idx],arr);
    }
    return taken || notTaken;
}

bool targetSum(int idx, int target , vector<int>arr,vector<vector<int>>&dp){
    if(target==0 ) return true;
    if(idx==0) return arr[0]==target;
    if(dp[idx][target]!=-1) return dp[idx][target];
    bool notTaken=targetSum(idx-1,target, arr,dp);
    bool taken=false;
    if(target>=arr[idx]){
        taken=targetSum(idx-1,target-arr[idx],arr,dp);
    }
    return dp[idx][target] = taken || notTaken;
}

int main(){
    vector<int>arr={2,3,7,8,10};
    int target=19;
    int n=arr.size();
    // vector<vector<int>>dp(n,vector<int>(target,-1));
    // cout<<targetSum(arr.size()-1,target,arr,dp);
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    //stores : Can we form a subset with a sum of tar using the first i+1 elements of the array arr

    for (int i = 0; i < n; i++) {
        dp[i][0] = true;  // Target of 0 is always possible (empty subset)
    }
    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int tar = 1; tar <= target; tar++) {
            bool notTake = dp[i - 1][tar];
            bool take = false;
            if (arr[i] <= tar) {
                take = dp[i - 1][tar - arr[i]];
            }
            dp[i][tar] = take || notTake;
        }
    }

    if (dp[n - 1][target]) {
        cout << "Subset with target sum exists." << endl;
    } else {
        cout << "Subset with target sum does not exist." << endl;
    }

    
    


    return 0;
}