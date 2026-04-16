#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int seg[4 * N], arr[N];
void build(int idx, int low, int high)
{
    if (low == high)
    {
        seg[idx] = arr[low];
        return;
    }
    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid);
    build(2 * idx + 2, mid + 1, high);
    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}

int query(int idx, int low, int high, int l, int r)
{
    if (r < low || high < l)
        return INT_MIN;
    if (l <= low && high <= r)
        return seg[idx];
    int mid = (low + high) / 2;
    int left = query(2 * idx + 1, low, mid, l, r);
    int right = query(2 * idx + 2, mid + 1, high, l, r);
    return max(left, right);
}
void rangeUpdate(int idx, int low, int high, int i, int val)
{
    
}
int main()
{

    return 0;
}