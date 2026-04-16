/*
Use ternary search when:
- You need to find the **maximum or minimum** of a **unimodal function**
  (i.e., strictly increasing then strictly decreasing or vice versa).
- The function is either **continuous** or **discrete**, but has **only one peak or valley**
  within the search interval.

Time complexity
Binary search log2(n)
Ternary search log3(n)

*/

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
bool ternarySearch(vi&arr, int l, int r,int val){
    if(l>r) return false;
    int m1=l+(r-l)/3;
    int m2=r-(r-l)/3;
    if(arr[m1]==val || arr[m2]==val) return true;
    bool left=false,right=false,mid=false;
    if(val>arr[m2]) right=ternarySearch(arr,m2+1,r,val);
    else if(val<arr[m1]) left=ternarySearch(arr,l,m1-1,val);
    else if(val>arr[m1] && val<arr[m2]) mid=ternarySearch(arr,m1+1,m2-1,val);
    return left | mid | right;
}
void solve(){
    int n;
    cin>>n;
    vi arr(n);
    input(arr);
    int val;
    cin>>val;
    if(ternarySearch(arr,0,n-1,val)) yes;
    else no;
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