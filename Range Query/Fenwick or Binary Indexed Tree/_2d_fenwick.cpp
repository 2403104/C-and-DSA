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
struct Fenwick2D{
    int n, m;
    vector<vector<ll>>bit;
    Fenwick2D(int n,int m) :n(n), m(m) {
        bit.resize(n+1, vl(m+1, 0));
    }
    void update(int x, int y, ll val){
        for(int i = x; i <= n; i += i & -i){
            for(int j = y; j <= n; j += j & -j){
                bit[i][j] += val;
            }
        }
    }
    ll query(int x, int y){
        ll ans = 0;
        for(int i = x; i > 0; i -= i & -i){
            for(int j = y; j > 0; j -= j & -j){
                ans += bit[i][j];
            }
        }
        return ans;
    }
    ll range_query(int x1, int y1, int x2, int y2){
        return query(x2, y2) - query(x1-1, y2) - query(x2, y1 -1 ) + query(x1-1, y1-1);
    }
};
void solve(){
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}