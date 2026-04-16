#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define input(arr) for(auto &it : arr) cin >> it;
#define output(arr) do { for (auto &it : arr) cout << it << ' '; cout << endl; } while(0);
#define ld long double
vector<ld> lagrange(const vector<ld>& xs, const vector<ld>& ys) {
    int n = xs.size();
    vector<ld> coeff(n, 0);
    for(int i = 0; i < n; i++){
        vector<ld> curr = {1};
        ld deno = 1;
        for(int j = 0; j < n; j++){
                if(i == j) continue;
                vector<ld> next((int)curr.size() + 1, 0);
                for(int k = 0; k < curr.size(); k++){
                        next[k + 1] += curr[k];
                        next[k] -= curr[k] * xs[j];
                }
                deno *= (xs[i] - xs[j]);
                curr = next;
        }
        ld factor = ys[i] / deno;
        for(int k = 0; k < curr.size(); k++){
                coeff[k] += curr[k];
        }
    }
    return coeff;
}
void solve(){
    
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    for(int tt = 1; tt <= t; tt++){
        solve();
    }
    return 0;
}