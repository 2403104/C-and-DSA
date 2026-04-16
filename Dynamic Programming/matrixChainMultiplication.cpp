#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (i == j)
            return 0;
        int mini = INT_MAX;
        for (int k = i; k <= j - 1; k++)
        {
            int curr = arr[i - 1] * arr[k] * arr[j] + solve(i, k, arr, dp) + solve(k + 1, j, arr, dp);
            mini = min(mini, curr);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr)
    {
        // 1 2 3 4 3
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(1, n - 1, arr, dp);
    }
};
int main()
{

    return 0;
}