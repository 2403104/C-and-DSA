//find max a[i] + a[j] in an interval l <= i, j <= r
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define m1 cout << "-1" << endl
#define input(arr) for(auto &it : arr) cin >> it;
#define output(arr) do { for (auto &it : arr) cout << it << ' '; cout << endl; } while(0);
typedef std::vector<int> vi;
typedef std::vector<long long> vl;
typedef std::vector<bool> vb;
typedef std::vector<vi> vvi;
struct Node{
    int maxi;
    int smaxi;
    Node() : maxi(-1), smaxi(-1) {} 
};
const int N = 1e5+5;
Node seg[N*4];
int arr[N];
void merge(int idx) {
    vector<int> v = {
        seg[idx * 2 + 1].maxi,
        seg[idx * 2 + 1].smaxi,
        seg[idx * 2 + 2].maxi,
        seg[idx * 2 + 2].smaxi
    };
    sort(v.rbegin(), v.rend());
    seg[idx].maxi = v[0];
    seg[idx].smaxi = v[1];
}
void build(int idx, int l, int r){
    if(l == r){
        seg[idx].maxi = arr[l];
        seg[idx].smaxi = -1;
        return;
    }
    int mid = (l + r)/2;
    build(idx * 2 + 1, l, mid);
    build(idx * 2 + 2, mid + 1, r);
    merge(idx);
}
void update(int idx, int l, int r, int pos, int val) {
    if (l == r) {
        seg[idx].maxi = val;
        seg[idx].smaxi = -1;
        return;
    }

    int mid = (l + r) / 2;
    if (pos <= mid){
        update(idx * 2 + 1, l, mid, pos, val);
    }
    else{
        update(idx * 2 + 2, mid + 1, r, pos, val);
    }
    merge(idx);
}
Node range_sum(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql){
        return Node();
    }
    if (ql <= l && r <= qr){
        return seg[idx];
    }
    int mid = (l + r) / 2;
    Node left = range_sum(idx * 2 + 1, l, mid, ql, qr);
    Node right = range_sum(idx * 2 + 2, mid + 1, r, ql, qr);
    vector<int> v = {left.maxi, left.smaxi, right.maxi, right.smaxi};
    sort(v.rbegin(), v.rend());
    Node res;
    res.maxi = v[0];
    res.smaxi = v[1];
    return res;
}
void solve(){
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}