#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static vector<int> prime;
    static bool isPrimeFilled;
    static const int LEN = 1e6 + 1;
    static void fillPrime()
    {
        if (isPrimeFilled)
            return;
        isPrimeFilled = true;
        prime[0] = prime[1] = 0;
        for (int i = 2; i * i <= LEN; i++)
        {
            if (prime[i] == 1)
            {
                for (int j = i * i; j < LEN; j += i)
                {
                    prime[j] = 0;
                }
            }
        }
    }
    vector<vector<int>> findPrimePairs(int n)
    {
        fillPrime();
        vector<vector<int>> ans;
        for (int i = 2; i <= n / 2; i++)
        {
            if (prime[i] && prime[n - i])
                ans.push_back({i, n - i});
        }
        return ans;
    }
};
const int Solution::LEN;
vector<int> Solution::prime(Solution::LEN, 1);
bool Solution::isPrimeFilled = false;
int main()
{

    return 0;
}