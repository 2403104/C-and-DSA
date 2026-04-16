#include <bits/stdc++.h>
using namespace std;
vector<int> seg;
vector<int>arr;
void build(int idx, int low, int high){
    if(low==high){
        seg[idx]=arr[low];
        return;
    }
    int mid=(low+high)/2;
    build(idx*2+1,low,mid);
    build(idx*2+2,mid+1,high);
    seg[idx]=seg[idx*2+1]+seg[idx*2+2];
}
void update(int idx,  int l, int r, int pos){
    if(l==r){
        seg[idx]=!seg[idx];
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid) update(idx*2+1,l,mid,pos);
    else update(idx*2+2,mid+1,r,pos);
    seg[idx]=seg[idx*2+1]+seg[idx*2+2];
}
int kthOne(int idx,int l, int r, int k){
    if(seg[idx]<k) return -1;
    if(l==r) return l;
    int mid=(l+r)/2;
    if(seg[idx*2+1]>=k) return kthOne(idx*2+1,l,mid,k);
    return kthOne(idx*2+2,mid+1,r,k-seg[idx*2+1]);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr); 
    #endif

    int n;
    cin>>n;
    arr.resize(n);
    seg.resize(n*4);
    for(int i=0;i<n;i++) cin>>arr[i];
    build(0,0,n-1);
    update(0,0,n-1,3);
    int k;
    cin>>k;
    cout<<kthOne(0,0,n-1,k);

    return 0;
}