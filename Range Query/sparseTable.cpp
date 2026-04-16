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
const int MAX_SIZE = 1e5 + 5;
const int LOG = 25;
int table[MAX_SIZE][LOG];
void build(vi &arr){
    int n = arr.size();
    for(int i = 0; i < n; i++) table[i][0] = arr[i];
    for(int j = 1; (1 << j) < n; j++){
        for(int i = 0; i + (1 << j) <= n; i++){
            table[i][j] = min(table[i][j-1] , table[i + (1 << (j-1))][j-1]);
        }
    }
}
int query(int l, int r){
    int w = r - l + 1;
    int j = log2(w);
    return min(table[l][j], table[r - (1<<j) + 1][j]);
}
void solve(){
    vi arr = {1,2,4,5,6,8,7,3,2,5,9};
    int n = arr.size();
    build(arr);
    cout << query(1, n - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}