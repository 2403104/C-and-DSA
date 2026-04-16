#include <bits/stdc++.h>
using namespace std;
class SegmentTree
{
    public:
    vector<int> seg;
    SegmentTree(int n)
    {
        seg.resize(4 * n + 1);
    }
    void build(int idx, int low, int high, int arr[])
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }
        int mid = (high + low) / 2;
        build(idx * 2 + 1, low, mid, arr);
        build(idx * 2 + 2, mid + 1, high, arr);
        seg[idx] = max(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }
    void update(int idx, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[idx] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            update(idx * 2 + 1, low, mid + 1, i, val);
        else
            update(idx * 2 + 2, mid + 1, high, i, val);
        seg[idx] = max(seg[idx * 2 + 1], seg[idx * 2 + 2]);
    }
    int maxQuery(int idx,int low, int high, int l, int r){
        if (r < low || high < l)
            return INT_MIN;
        if (low >= l && high <= r)
            return seg[idx];
        int mid = (low + high) / 2;
        int left = maxQuery(2 * idx + 1, low, mid, l, r);
        int right = maxQuery(2 * idx + 2, mid + 1, high, l, r);
        return max(left, right);
    }
};
int main()
{

    int arr[]={81,74,1,2,5,40,1,2,5,3,3,9,5,8};
    int n=14;
    SegmentTree seg(n);
    seg.build(0,0,n-1,arr);
    cout<<seg.maxQuery(0,0,n-1,1,8);
    return 0;
}
