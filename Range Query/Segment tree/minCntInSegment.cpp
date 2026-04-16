#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
pair<int,int> seg[4 * N];
int  arr[N];
void build(int idx, int low, int high)
{
    if (low == high)
    {
        seg[idx].first = arr[low];
        seg[idx].second=1;
        return;
    }
    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid);
    build(2 * idx + 2, mid + 1, high);
    if(seg[2*idx+1].first<seg[2*idx+2].first){
        seg[idx].first=seg[2*idx+1].first;
        seg[idx].second=seg[2*idx+1].second;
    }else if(seg[2*idx+1].first>seg[2*idx+2].first){
        seg[idx].first=seg[2*idx+2].first;
        seg[idx].second=seg[2*idx+2].second;
    }else{
        seg[idx].first=seg[2*idx+1].first;
        seg[idx].second=seg[2*idx+1].second+seg[2*idx+2].second;
    }
}

pair<int,int> query(int idx, int low, int high, int l, int r)
{
    if (r < low || high < l)
        return {INT_MAX,-1};
    if (l <= low && high <= r)
        return seg[idx];
    int mid = (low + high) / 2;
    pair<int,int> left = query(2 * idx + 1, low, mid, l, r);
    pair<int,int> right = query(2 * idx + 2, mid + 1, high, l, r);
    pair<int,int>ans;
    if(left.first<right.first) ans=left;
    else if(left.first>right.first) ans=right;
    else ans={left.first,left.second+right.second};
    return ans;
}
void update(int idx, int low, int high, int i, int val)
{
    if (low == high)
    {
        arr[i] = val;
        seg[idx].first = val;
        seg[idx].second=1;
        return;
    }
    int mid = (low + high) / 2;
    if (i <= mid)
        update(2 * idx + 1, low, mid, i, val);
    else
        update(2*idx+2,mid+1,high,i,val);
    if(seg[2*idx+1].first<seg[2*idx+2].first){
        seg[idx].first=seg[2*idx+1].first;
        seg[idx].second=seg[2*idx+1].second;
    }else if(seg[2*idx+1].first>seg[2*idx+2].first){
        seg[idx].first=seg[2*idx+2].first;
        seg[idx].second=seg[2*idx+2].second;
    }else{
        seg[idx].first=seg[2*idx+1].first;
        seg[idx].second=seg[2*idx+1].second+seg[2*idx+2].second;
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    build(0,0,n-1);
    int l,r;
    cin>>l>>r;
    auto res = query(0, 0, n - 1, l, r);
    cout<<res.first<<" "<<res.second<<endl;
    return 0;
}