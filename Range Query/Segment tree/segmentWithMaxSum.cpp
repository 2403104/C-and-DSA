#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Node{
    public:
    ll pref,suff,sum,ans;
    Node(ll pref,ll suff,ll sum,ll ans){
        this->pref=pref;//max prefix
        this->suff=suff;//max suff
        this->sum=sum;
        this->ans=ans;
    }
};

const int N = 1e5;
Node* seg[4 * N];
int  arr[N];
void build(int idx, int low, int high)
{
    if (low == high)
    {   
        if(arr[low]<=0){
            seg[idx] = new Node(0,0,arr[low],0);
        }else{
            seg[idx]= new Node(arr[low],arr[low],arr[low],arr[low]);
        }
        return;
    }
    int mid = (low + high) / 2;
    build(2 * idx + 1, low, mid);
    build(2 * idx + 2, mid + 1, high);
    ll sum=seg[idx*2+1]->sum+seg[idx*2+2]->sum;
    ll pref=max(seg[idx*2+1]->pref,seg[idx*2+1]->sum+ seg[idx*2+2]->pref);
    ll suff=max(seg[idx*2+2]->suff,seg[idx*2+1]->suff+seg[idx*2+2]->sum);
    ll ans=max({seg[idx*2+2]->pref+seg[idx*2+1]->suff,seg[idx*2+1]->ans,seg[idx*2+2]->ans});
    seg[idx] = new Node(pref,suff,sum,ans);
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

int main()
{

    return 0;
}