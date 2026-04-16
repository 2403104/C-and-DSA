#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long angle(vector<int> &p1, vector<int> &p2, vector<int> &p3)
    {
        long long x1 = p1[0], y1 = p1[1];
        long long x2 = p2[0], y2 = p2[1];
        long long x3 = p3[0], y3 = p3[1];

        return (y2 - y1) * (x3 - x2) - (y3 - y2) * (x2 - x1);
    }

    vector<vector<int>> outerTrees(vector<vector<int>> &trees)
    {
        int n = trees.size();
        if (n <= 1)
            return trees;
        sort(trees.begin(), trees.end(), [](vector<int> &a, vector<int> &b)
             {
                if (a[0] == b[0])
                    return a[1] < b[1];
                return a[0] < b[0]; });
        vector<vector<int>> lower, upper;
        for (auto it : trees)
        {
            while (lower.size() >= 2 && angle(lower[lower.size() - 2], lower[lower.size() - 1], it) < 0)
            {
                lower.pop_back();
            }
            lower.push_back(it);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            vector<int> it = trees[i];
            while (upper.size() >= 2 && angle(upper[upper.size() - 2], upper[upper.size() - 1], it) < 0)
            {
                upper.pop_back();
            }
            upper.push_back(it);
        }
        set<vector<int>> hull(lower.begin(), lower.end());
        hull.insert(upper.begin(), upper.end());
        return vector<vector<int>>(hull.begin(), hull.end());
    }
};
int main()
{

    return 0;
}