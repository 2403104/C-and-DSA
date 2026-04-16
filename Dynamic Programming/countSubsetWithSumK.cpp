#include <bits/stdc++.h>
using namespace std;
//if the arr contains zero
int countSubset(vector<int> &arr, int idx, int sum)
{
    if (idx == 0){
        if(sum==0 && arr[idx]==0) return 2;
        if(sum==0  || sum==arr[0]) return 1;
        return 0; 
    }

    int notPick = countSubset(arr, idx - 1, sum);
    int pick = 0;
    if (arr[idx] <= sum)
    {
        pick = countSubset(arr, idx - 1, sum - arr[idx]);
    }
    return pick + notPick;
}
int countSubset(vector<int> &arr, int idx, int sum)
{
    if (sum == 0)
        return 1;
    if (idx == 0)
        return sum == arr[idx];
    int notPick = countSubset(arr, idx - 1, sum);
    int pick = 0;
    if (arr[idx] <= sum)
    {
        pick = countSubset(arr, idx - 1, sum - arr[idx]);
    }
    return pick + notPick;
}
int countSubset(vector<int> &arr, int idx, int sum, vector<vector<int>> &dp)
{
    if (dp[idx][sum] != -1)
        return dp[idx][sum];
    if (sum == 0)
        return 1;
    if (idx == 0)
        return sum == arr[idx];
    int notPick = countSubset(arr, idx - 1, sum, dp);
    int pick = 0;
    if (arr[idx] <= sum)
    {
        pick = countSubset(arr, idx - 1, sum - arr[idx], dp);
    }
    return dp[idx][sum] = pick + notPick;
}

int main()
{
    vector<int> nums = {1, 2, 8,9,3};
    int target=10;
    int n=nums.size();
    // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    // cout << countSubset(arr, n - 1, 10);

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        if (nums[0] == 0)
            dp[0][0] = 2;
        else {
            dp[0][0] = 1;
            if (nums[0] <= target)
                dp[0][nums[0]] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int tar = 0; tar <= target; tar++) {
                int notTake = dp[i - 1][tar];
                int take = 0;
                if (tar >= nums[i]) {
                    take = dp[i - 1][tar - nums[i]];
                }
                dp[i][tar] = take + notTake;
            }
        }


    return 0;
}
