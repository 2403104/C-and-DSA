#include <bits/stdc++.h>
using namespace std;
vector<int> bit;
int getCnt(int idx){
    int res=0;
    while(idx>0){
        res+=bit[idx];
        idx-= idx & -idx;
    }
    return res;
}
void update(int n,int idx, int inc){
    while(idx<=n){
        bit[idx]+=inc;
        idx+= idx & -idx;
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr); 
    #endif

    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i : arr) cin>>i;
    vector<int>temp=arr;
    sort(temp.begin(),temp.end());
    for(int i=0;i<n;i++){
        arr[i]=lower_bound(temp.begin(),temp.end(),arr[i])-temp.begin()+1;
    }
    bit.resize(n+1,0);
    int inv=0;
    for(int i=n-1;i>=0;i--){
        inv+=getCnt(arr[i]-1);
        update(n,arr[i],1);
    }
    cout<<inv<<endl;
    return 0;
}