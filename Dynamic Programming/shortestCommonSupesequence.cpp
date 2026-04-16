#include <bits/stdc++.h>
using namespace std;
int lcs(string a, string b)
{
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp1(n + 1, vector<int>(m + 1, -1));
    vector<vector<string>> dp2(n + 1, vector<string>(m + 1));
    for (int i = 0; i <= m; i++)
    {
        dp1[0][i] = 0;
        dp2[0][i] = "";
    }
    for (int j = 0; j <= n; j++)
    {
        dp1[j][0] = 0;
        dp2[j][0] = "";
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp1[i][j] = 1 + dp1[i - 1][j - 1];
                dp2[i][j] = dp2[i - 1][j - 1] + a[i - 1];
            }
            else
            {
                int store = max(dp1[i - 1][j], dp1[i][j - 1]);
                if (store == dp1[i - 1][j])
                    dp2[i][j] = dp2[i - 1][j];
                else
                    dp2[i][j] = dp2[i][j - 1];
                dp1[i][j] = store;
            }
        }
    }
    return dp1[n][m];
}
string longestSupersequence(string a, string b)
{
    int n = a.length(), m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[j][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                int store = max(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = store;
            }
        }
    }
    string res="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]) res+=a[i-1];
    }
}
int main()
{
    string a, b;
    a = "ankitkum";
    b = "ankium";
    cout << lcs(a, b);

    return 0;
}