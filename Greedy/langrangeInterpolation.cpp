#include <bits/stdc++.h>
using namespace std;

using ld = long double;

// evaluate polynomial at x
ld eval(const vector<ld>& a, ld x) {
    ld res = 0, p = 1;
    for (ld c : a) {
        res += c * p;
        p *= x;
    }
    return res;
}

// Lagrange interpolation to recover coefficients
vector<ld> lagrange(const vector<ld>& xs,
                    const vector<ld>& ys) {
    int n = xs.size();
    vector<ld> coef(n, 0);

    for (int i = 0; i < n; i++) {
        vector<ld> cur = {1};
        ld denom = 1;

        for (int j = 0; j < n; j++) {
            if (i == j) continue;

            vector<ld> nxt(cur.size() + 1, 0);
            for (int k = 0; k < cur.size(); k++) {
                nxt[k+1] += cur[k];
                nxt[k] -= cur[k] * xs[j];
            }
            cur = nxt;

            denom *= (xs[i] - xs[j]);
        }

        ld factor = ys[i] / denom;
        for (int k = 0; k < cur.size(); k++)
            coef[k] += cur[k] * factor;
    }

    return coef;
}

vector<ld> multiply(vector<ld> A, vector<ld> B) {
    int k = A.size() + B.size() - 1;

    vector<ld> xs(k), ya(k), yb(k), yc(k);
    for (int i = 0; i < k; i++) xs[i] = i;

    // evaluate
    for (int i = 0; i < k; i++) {
        ya[i] = eval(A, xs[i]);
        yb[i] = eval(B, xs[i]);
        yc[i] = ya[i] * yb[i];
    }

    return lagrange(xs, yc);
}

int main() {
    vector<ld> A = {1,2,3};
    vector<ld> B = {4,5};

    auto C = multiply(A,B);

    for (auto v : C)
        cout << (long long)(v + 0.5) << " ";
}
