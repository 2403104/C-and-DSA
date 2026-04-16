#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES\n"
#define no cout << "NO\n"
#define m1 cout << "-1\n"
#define input(arr) for (auto &it : arr) cin >> it;
#define output(arr) do { for (auto &it : arr) cout << it << ' '; cout << '\n'; } while(0)
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<vi> vvi;

class BIT {
    int n;
    vi bit;
public:
    BIT(int size) {
        n = size;
        bit.assign(n + 1, 0);
    }

    void add(int idx, int val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    int point_query(int idx) {
        int ret = 0;
        for (; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
};

void solve() {
    int n = 10;
    BIT bit(n);

    bit.add(1, 5);
    bit.add(2, 6);
    bit.add(5, 4);

    cout << bit.point_query(7) << endl; 

    bit.range_add(2, 5, 1);
    cout << bit.point_query(3) << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
