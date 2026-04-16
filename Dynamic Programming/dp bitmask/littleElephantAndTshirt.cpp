#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
bool people[11][101];
int dp[102][(1 << 11)];
int n;

int helper(int shirt, int mask) {
    if (mask == (1 << n) - 1) return 1;
    if (shirt > 100) return 0;
    if (dp[shirt][mask] != -1) return dp[shirt][mask];

    int ans = 0;
    for (int j = 0; j < n; j++) {
        if ((mask & (1 << j)) != 0) continue;
        if (people[j][shirt]) {
            int newMask = mask | (1 << j);
            ans = (ans + helper(shirt + 1, newMask)) % MOD;
        }
    }
    ans = (ans + helper(shirt + 1, mask)) % MOD;
    return dp[shirt][mask] = ans;
}

void solve() {
    cin >> n;
    cin.ignore();
    memset(people, false, sizeof people);
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        istringstream iss(s);
        int x;
        while (iss >> x) {
            people[i][x] = true;
        }
    }
    memset(dp, -1, sizeof dp);
    cout << helper(1, 0) << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        solve();
    }
    return 0;
}
