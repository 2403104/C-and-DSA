#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define nline cout <<'\n'
#define input(arr)       \
    for (auto &it : arr) \
        cin >> it;
#define output(arr)     \
    for (auto it : arr) \
        cout << it << " ";\
        cout<<endl;
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
const int N=1e5+5;
int seg[N*4],arr[N];
void build(int idx, int l, int r){
    if(l==r){
        seg[idx]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    build(idx*2+1,l,mid);
    build(idx*2+2,mid+1,r);
    seg[idx]=seg[idx*2+1]+seg[idx*2+2];
}
int query(int idx, int low, int high, int l, int r){
    if(high<l || low>r) return 0;
    if(l<=low && high<=r) return seg[idx];
    int mid=(low+high)/2;
    seg[idx]=query(idx*2+1,low,mid, l,r)+query(idx*2+2,mid+1,high,l,r);
}
void update(int idx, int low, int high, int i, int val)
{
    if (low == high)
    {
        seg[idx] = val;
        arr[i] = val;
        return;
    }
    int mid = (low + high) / 2;
    if (i <= mid)
        update(2 * idx + 1, low, mid, i, val);
    else
        update(2 * idx + 2, mid + 1, high, i, val);
    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}
void solve(){
    int n;
    cin>>n;
    rep(i,0,n) cin>>arr[i];

   
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

    int t;
    cin >> t;
    // t=1;
    while (t--)
    {
        solve();
    }

    return 0;
}