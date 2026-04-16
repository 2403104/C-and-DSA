#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    static vector<ll> fib;
    /*
    It belongs to the class itself, not to any object of Solution.
    All instances of Solution share the same fib vector.
    The vector persists across multiple calls and is not reinitialized when a new object is created.
    */
    static void makeFib()
    {
        if (!fib.empty()) // ensure no reinitialization
            return;
        fib.push_back(1);
        fib.push_back(1);
        while (fib.back() <= 1e9)
        {
            int n = fib.size();
            ll curr = fib[n - 1] + fib[n - 2];
            if (curr > 1e9)
                break;
            fib.push_back(curr);
        }
    }
    int findMinFibonacciNumbers(int k)
    {
        makeFib();
        int cnt = 0;
        int idx = fib.size() - 1;
        while (k > 0)
        {
            if (fib[idx] <= k)
            {
                k -= fib[idx];
                cnt++;
            }
            idx--;
        }
        return cnt;
    }
};
vector<ll> Solution::fib; // ensures fib has memory allocated.
int main()
{

    return 0;
}