#include <bits/stdc++.h>
using namespace std;

struct lazy_segtree {
    struct item {
        long long a;
        item(long long val) {
            a = val;
        }
    };

    item single(long long x) {
        item p(x);
        return p;
    }

    long long n;
    long long val;
    vector<item> tree;
    vector<item> lazy;

    void build(int n) {
        this->n = n;
        tree.assign(4 * n, single(val));
        lazy.assign(4 * n, single(0));
    }

    item combine(item a, item b) {
        item res(val);
        res.a = max(a.a, b.a);
        return res;
    }

    long long get(long long ql, long long qr) {
        return get(ql, qr, 0, n - 1, 0).a;
    }

    void lazy_sum(long long ql, long long qr, long long val) {
        lazy_sum(ql, qr, 0, n - 1, 0, val);
    }

    item get(long long ql, long long qr, long long l, long long r, long long i) {
        if (lazy[i].a != 0) {
            tree[i].a += lazy[i].a;
            if (l != r) {
                lazy[2 * i + 1].a += lazy[i].a;
                lazy[2 * i + 2].a += lazy[i].a;
            }
            lazy[i].a = 0;
        }
        if (r < ql || l > qr) return val;
        if (r <= qr && l >= ql) {
            return tree[i];
        }
        long long m = (l + r) / 2;
        return combine(get(ql, qr, l, m, 2 * i + 1), get(ql, qr, m + 1, r, 2 * i + 2));
    }

    void update(long long idx, long long x) {
        update(idx, x, 0, n - 1, 0);
    }

    void lazy_sum(long long ql, long long qr, long long l, long long r, long long i, long long val) {
        long long m = (l + r) / 2;
        if (lazy[i].a != 0) {
            tree[i].a += lazy[i].a;
            if (l != r) {
                lazy[2 * i + 1].a += lazy[i].a;
                lazy[2 * i + 2].a += lazy[i].a;
            }
            lazy[i].a = 0;
        }
        if (r < ql || l > qr) return;
        else if (r <= qr && l >= ql) {
            tree[i].a += val;
            if (l != r) {
                lazy[2 * i + 1].a += val;
                lazy[2 * i + 2].a += val;
            }
        } else {
            lazy_sum(ql, qr, l, m, 2 * i + 1, val);
            lazy_sum(ql, qr, m + 1, r, 2 * i + 2, val);
            tree[i] = combine(tree[2 * i + 1], tree[2 * i + 2]);
        }
    }

    void build(vector<long long>& a, long long l, long long r, long long i) {
        if (l == r) {
            tree[i].a = a[l];
            return;
        }
        long long m = (l + r) / 2;
        build(a, l, m, 2 * i + 1);
        build(a, m + 1, r, 2 * i + 2);
        tree[i] = combine(tree[2 * i + 1], tree[2 * i + 2]);
    }

    void update(long long idx, long long x, long long l, long long r, long long i) {
        if (idx < l || idx > r) return;
        if (l == r) {
            tree[i].a = x;
            return;
        }
        long long m = (l + r) / 2;
        if (idx <= m)
            update(idx, x, l, m, 2 * i + 1);
        else
            update(idx, x, m + 1, r, 2 * i + 2);
        tree[i] = combine(tree[2 * i + 1], tree[2 * i + 2]);
    }
};

void solve() {
    int n, k;
    cin >> n >> k;

    set<array<int, 3>> vis;
    vector<array<int, 3>> pts;
    int mx = 2.5e5 + 1;
    vector<vector<int>> idx(mx + 2);
    int j = 0;

    for (int i = 0; i < n; i++) {
        array<int, 3> b;
        for (int& x : b) cin >> x;
        if (!vis.contains(b)) {
            pts.push_back(b);
            idx[pts[j][0]].push_back(j);
            j++;
            vis.insert(b);
        }
    }

    n = vis.size();
    int l = 1, r = mx;
    
    while (l < r) {
        vector<multiset<int>> s(k + 1);
        lazy_segtree g;
        g.val = 0;
        g.build(mx + 5);
        int side = (l + r) / 2;

        auto insert = [&](int i) {
            for (int x : idx[i]) {
                bool same = false;
                auto j = s[pts[x][2]].lower_bound(pts[x][1]);
                if (j != s[pts[x][2]].end() && (*j) == pts[x][1]) {
                    same = true;
                }
                int l = pts[x][1];
                int r = min(mx, l + side - 1);
                if (!s[pts[x][2]].empty()) {
                    if (j == s[pts[x][2]].begin()) {
                        r = min(r, (*j) - 1);
                    } else if (j == s[pts[x][2]].end()) {
                        j--;
                        l = max((*j) + side, l);
                    } else {
                        r = min(r, (*j) - 1);
                        j--;
                        l = max((*j) + side, l);
                    }
                }
                if (l <= r) {
                    if (same) assert(0);
                    g.lazy_sum(l, r, 1);
                }
                s[pts[x][2]].insert(pts[x][1]);
            }
        };

        auto remove = [&](int i) {
            for (int x : idx[i]) {
                bool same = false;
                s[pts[x][2]].erase(s[pts[x][2]].find(pts[x][1]));
                auto j = s[pts[x][2]].lower_bound(pts[x][1]);
                if (j != s[pts[x][2]].end() && (*j) == pts[x][1]) {
                    same = true;
                }
                int l = pts[x][1];
                int r = min(mx, l + side - 1);
                if (!s[pts[x][2]].empty()) {
                    if (j == s[pts[x][2]].begin()) {
                        r = min(r, (*j) - 1);
                    } else if (j == s[pts[x][2]].end()) {
                        j--;
                        l = max((*j) + side, l);
                    } else {
                        r = min(r, (*j) - 1);
                        j--;
                        l = max((*j) + side, l);
                    }
                }
                if (l <= r) {
                    if (same) assert(0);
                    g.lazy_sum(l, r, -1);
                }
            }
        };

        for (int i = 1; i < side; i++) {
            insert(i);
        }

        bool done = false;
        for (int i = side; i <= mx; i++) {
            insert(i);
            int curr = g.get(1, mx);
            if (curr >= k) {
                if (curr > k) assert(0);
                done = true;
                break;
            }
            int rem = i - side + 1;
            remove(rem);
        }

        if (done) {
            r = side;
        } else {
            l = side + 1;
        }
    }

    cout << r - 1 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}
