//NOT SOLVED
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define input(arr)       \
    for (auto &it : arr) \
        cin >> it;
#define output(arr)        \
    for (auto it : arr)    \
        cout << it << " "; \
    cout << endl;
#define pb push_back
#define p push
#define F first
typedef std::vector<int> vi;
typedef std::vector<long long> vl;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
vi arr;
int n,q;
struct BIT{
    vl bit;
    int size;
    BIT(int n){
        size=n+1;
        bit.assign(n+2,0);
    }
    void add(int idx,ll val){
        while(idx<size){
            bit[idx]+=val;
            idx+= idx & -idx;
        }
    }
    ll sum(int idx){
        ll ans=0;
        while(idx>0){
            ans+=bit[idx];
            idx-=idx & -idx;
        }
        return ans;
    }
};
BIT B1(0),B2(0);
//B2 will handle the constant stuff and B1 will handle the variables
void range_add(int l , int r){
    B1.add(l,1);
    B1.add(r+1,-1);

    B2.add(l,-l+1);
    B2.add(r+1,l-1);
}
ll prefix_sum(int i){
    return B1.sum(i)*i+B2.sum(i);
}
ll range_sum(int a, int b){
    return prefix_sum(b)-prefix_sum(a-1);
}
void solve(){
    cin>>n>>q;
    arr.resize(n+1);
    B1=BIT(n);
    B2=BIT(n);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        B2.add(i,arr[i]);
    }
    while(q--){
        int type;cin>>type;
        int l,r;cin>>l>>r;
        if(type==1){
            range_add(l,r);
        }else{
            cout<<range_sum(l,r)<<'\n';
        }
        
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    solve();

    return 0;
}   