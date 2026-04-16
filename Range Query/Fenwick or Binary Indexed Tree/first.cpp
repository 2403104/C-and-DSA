#include <bits/stdc++.h>
using namespace std;
/*
bit[6] → a[5]+a[6]
bit[4] → a[1]+a[2]+a[3]+a[4]

Each element bit[idx] stores the sum of a specific range of the original array a[].
Each bit holds the element sum equal of prev msb element
*/
int n;
vector<int>bit; 
void update(int idx, int value){
    while(idx<=n){
        bit[idx]+=value;
        idx+=idx & -idx;//take and with two's complement to get the righmost big (most significant bit)
    }
}
int query(int idx){
    int res=0;
    while(idx>0){
        res+=bit[idx];
        idx-= idx & -idx;
    }
    return res;
}
int getSum(int l, int r){
    return query(r)-query(l-1);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr); 
    #endif

    cin>>n;
    bit.resize(n+1);
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++) cin>>arr[i];

    for(int i=1;i<=n;i++) update(i,arr[i]);

    cout << query(n) <<endl;;
    cout<< getSum(2, 5) << endl;

    return 0;
}
