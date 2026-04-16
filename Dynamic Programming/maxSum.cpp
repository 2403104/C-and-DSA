#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int findMax(vector<int> &v, int idx)
{
    if (idx == 0)
        return v[idx];
    if (idx < 0)
        return 0;
    int a = v[idx] + findMax(v, idx - 2);
    int b = findMax(v, idx - 1);
    return max(a, b);
}

int main()
{
    vector<int> v = {2, 7, -4, 1, 10, 9};
    int n = v.size();
    vector<int> dp(n, 0);
    dp[0] = v[0];
    dp[1] = max(v[0], v[1]);
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
    }
    cout << findMax(v, v.size() - 1) << endl;
    cout << dp[n - 1];
    return 0;
} 