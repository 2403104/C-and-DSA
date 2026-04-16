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
    ll _1sum;
    ll _2sum;
    ll x;
    ll sum;
    Node() : _1sum(0), _2sum(0), x(0), sum(0) {}
};
const int N = 1e5+5;
Node seg[N*4];
ll arr[N];
void merge(int idx){

}
void build(int idx, int l, int r){
    if(l == r){
        seg[idx].sum = arr[l];
        return;
    }
    int mid = (l + r)/2;
    build(idx * 2 + 1, l, mid);
    build(idx * 2 + 2, mid + 1, r);
    merge(idx);
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