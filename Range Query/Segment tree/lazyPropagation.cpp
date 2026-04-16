#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> seg,lazy;
vector<int>arr;
void build(int idx, int l, int r) {
    if (l == r) {
        seg[idx] = arr[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * idx+1, l, m);
    build(2 * idx +2, m + 1, r);
    seg[idx] = seg[2 * idx+1] + seg[2 * idx +2];
}
void rangeUpdate(int idx, int l, int r, int uL, int uR,int val){
    if(lazy[idx]!=0){
        seg[idx]+=(r-l+1)*lazy[idx];
        if(l!=r){
            lazy[idx*2+1]+=lazy[idx];
            lazy[idx*2+2]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(uR<l || uL>r) return;
    if (uL <= l && r <= uR){
        seg[idx]+=(r-l+1)*val;
        if(l!=r){
            lazy[idx*2+1]+=val;
            lazy[idx*2+2]+=val;
        }
        return;
    }
    int mid=(l+r)/2;
    rangeUpdate(idx*2+1,l,mid,uL,uR,val);
    rangeUpdate(idx*2+2,mid+1,r, uL, uR, val);
    seg[idx]=seg[idx*2+1]+seg[idx*2+2];
}
int queryLazySum(int idx, int l, int r, int qL, int qR){
    if(lazy[idx]!=0){
        seg[idx]+=(r-l+1)*lazy[idx];
        if(l!=r){
            lazy[idx*2+1]+=lazy[idx];
            lazy[idx*2+2]+=lazy[idx];
        }
        lazy[idx]=0;
    }
    if(qL>r || qR<l) return 0;
    if (qL <= l && r <= qR) return seg[idx];
    int  mid=(l+r)/2;
    return queryLazySum(idx*2+1,l,mid,qL,qR)+queryLazySum(idx*2+2,mid+1,r,qL,qR);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr); 
    #endif

    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    seg.resize(n*4);
    lazy.resize(n*4);
    build(0,0,n-1);
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, val;
            cin >> l >> r >> val;
            rangeUpdate(0, 0, n - 1, l, r, val);
        } else if (type == 2) {
            int l, r;
            cin >> l >> r;
            cout << queryLazySum(0, 0, n - 1, l, r) << "\n";
        }
    }



    return 0;
}