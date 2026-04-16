#include <bits/stdc++.h>
using namespace std;
int knapsack1(int n, int w, vector<int> &value, vector<int> &wt)
{
    if (n == 0)
    {
        if (wt[0] <= w)
            return value[0];
        return 0;
    }
    if (wt[n] > w)
        return knapsack1(n - 1, w, value, wt);
    return max(knapsack1(n - 1, w - wt[n], value, wt) + value[n], knapsack1(n - 1, w, value, wt));
}

int knapsack2(int n, int w, vector<int> &value, vector<int> &wt)
{
    if (n == 0)
    {
        if (wt[0] <= w) 
            return value[0];
        return 0;
    }
    int notTake = knapsack2(n - 1, w, value, wt);
    int take = INT_MIN;
    if (wt[n] <= w)
    {
        take = value[n] + knapsack2(n - 1, w - wt[n], value, wt);
    }
    return max(take, notTake);
}

int knapsack3(int n, int w, vector<int> &value, vector<int> &wt, vector<vector<int>> &dp)
{
    if (dp[n][w] != -1)
        return dp[n][w];
    if (n == 0)
    {
        if (w >= wt[0])
            return value[0];
        return 0;
    }
    int notTake = knapsack3(n - 1, w, value, wt, dp);
    int take = INT_MIN;
    if (wt[n] <= w)
    {
        take = value[n] + knapsack3(n - 1, w - wt[n], value, wt, dp);
    }
    return dp[n][w] = max(take, notTake);
}

int main()
{
    vector<int> value = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int w = 50;
    int n = value.size();
    // vector<vector<int>>dp(n,vector<int>(w+1,-1));
    // cout << knapsack3(n - 1, w, value, wt,dp) << endl;
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int i = wt[0]; i <= w; i++)
        dp[0][i] = value[0];
    for (int ind = 1; ind < n; ind++)
    {
        for (int j = 0; j <= w; j++)
        {
            int notTake = dp[ind - 1][j];
            int take = INT_MIN;
            if (wt[ind] <= w)
            {
                take = value[ind] + dp[ind - 1][j - wt[ind]];
            }
            dp[ind][j] = max(take, notTake);
        }
    }
    cout << dp[n - 1][w];
    // do space memoization
    return 0;
}