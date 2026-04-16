#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void b1(vector<bool> &bulbs)
    {
        int n = bulbs.size();
        for (int i = 0; i < n; i++)
        {
            bulbs[i] = !bulbs[i];
        }
    }
    void b2(vector<bool> &bulbs)
    {
        int n = bulbs.size();
        for (int i = 1; i < n; i += 2)
        {
            bulbs[i] = !bulbs[i];
        }
    }

    void b3(vector<bool> &bulbs)
    {
        int n = bulbs.size();
        for (int i = 0; i < n; i += 2)
        {
            bulbs[i] = !bulbs[i];
        }
    }

    void b4(vector<bool> &bulbs)
    {
        int n = bulbs.size();
        for (int i = 0; i < n; i++)
        {
            if (i % 3 == 0)
            {
                bulbs[i] = !bulbs[i];
            }
        }
    }
    int flipLights(int n, int presses)
    {
        n = min(n, 3);
        vector<bool> bulbs(n, true);
        unordered_set<vector<bool>> set;
        vector<void (Solution::*)(vector<bool> &)> operations = {
            &Solution::b1,
            &Solution::b2,
            &Solution::b3,
            &Solution::b4};

        for (int i = 0; i < (1 << 4); i++)
        {
            vector<bool> temp = bulbs;
            int cnt = __builtin_popcount(i);
            if (cnt > presses || (cnt - presses) % 2 != 0)
                continue;
            for (int j = 0; j < 4; j++)
            {
                if (i & (1 << j))
                    (this->*operations[j])(temp);
            }
            set.insert(temp);
        }
        return set.size();
    }
};
int main()
{

    return 0;
}