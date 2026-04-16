#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cfloat>

using namespace std;

struct Result {
    double expected_cost;
    int optimal_root;
    long long iterations;
    double iter_metric;
};

Result solve_N3(const vector<double>& p, const vector<double>& q, int n) {
    vector<vector<double>> e(n + 2, vector<double>(n + 1, 0));
    vector<vector<double>> w(n + 2, vector<double>(n + 1, 0));
    vector<vector<int>> root(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    long long iter = 0;

    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            e[i][j] = DBL_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            for (int r = i; r <= j; r++) {
                iter++;
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }

    return {e[1][n], root[1][n], iter, (double)iter / (n * n)};
}

Result solve_N2(const vector<double>& p, const vector<double>& q, int n) {
    vector<vector<double>> e(n + 2, vector<double>(n + 1, 0));
    vector<vector<double>> w(n + 2, vector<double>(n + 1, 0));
    vector<vector<int>> root(n + 2, vector<int>(n + 1, 0));

    for (int i = 1; i <= n + 1; i++) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    long long iter = 0;

    for (int l = 1; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            e[i][j] = DBL_MAX;
            w[i][j] = w[i][j - 1] + p[j] + q[j];

            int r_start = (l == 1) ? i : root[i][j - 1];
            int r_end   = (l == 1) ? i : root[i + 1][j];

            for (int r = r_start; r <= r_end; r++) {
                iter++;
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }

    return {e[1][n], root[1][n], iter, (double)iter / (n * n)};
}
int cnt = 1;
void run_test_case(int test_num, const vector<double>& p, const vector<double>& q) {
    int n = p.size() - 1;
    
    Result res3 = solve_N3(p, q, n);
    Result res2 = solve_N2(p, q, n);

    cout << "--------------------------------------------------------\n";
    cout << "Test Case " << cnt++ << ": N = " << n << "\n";
    cout << "Metrics           | O(N^3) standard  | O(N^2) Knuth\n";
    cout << "------------------|------------------|------------------\n";
    
    cout << "Expected Cost (E) | " << setw(16) << left << fixed << setprecision(4) << res3.expected_cost 
         << "| " << fixed << setprecision(4) << res2.expected_cost << "\n";
         
    cout << "Main Root         | " << "k_" << setw(14) << left << res3.optimal_root 
         << "| k_" << res2.optimal_root << "\n";
         
    cout << "Total Iterations  | " << setw(16) << left << res3.iterations 
         << "| " << res2.iterations << "\n";
         
    cout << "Iters / (N * N)   | " << setw(16) << left << fixed << setprecision(4) << res3.iter_metric 
         << "| " << fixed << setprecision(4) << res2.iter_metric << "\n";
}
int main() {

  #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
  #endif


    srand(12345);

    auto print_pq = [](const vector<double>& p, const vector<double>& q) {
        cout << "P array : [0.00000";
        for (size_t i = 1; i < p.size(); i++) cout << ", " << fixed << setprecision(5) << p[i];
        cout << "]\nQ array : [";
        for (size_t i = 0; i < q.size(); i++) {
            cout << fixed << setprecision(5) << q[i];
            if (i < q.size() - 1) cout << ", ";
        }
        cout << "]\n";
    };

    auto execute = [&](int tc, const vector<double>& p, const vector<double>& q) {
        print_pq(p, q);
        run_test_case(tc, p, q);
        cout << "\n";
    };

    auto normalize = [](int n, vector<double>& p, vector<double>& q) {
        double sum = 0.0;
        for (int i = 1; i <= n; i++) sum += p[i];
        for (int i = 0; i <= n; i++) sum += q[i];
        for (int i = 1; i <= n; i++) p[i] /= sum;
        for (int i = 0; i <= n; i++) q[i] /= sum;
    };

    auto gen_random = [&](int n, vector<double>& p, vector<double>& q) {
        p.assign(n + 1, 0.0);
        q.assign(n + 1, 0.0);
        for (int i = 1; i <= n; i++) p[i] = (rand() % 1000) + 1;
        for (int i = 0; i <= n; i++) q[i] = (rand() % 1000) + 1;
        normalize(n, p, q);
    };

    auto gen_pattern = [&](int n, int type, vector<double>& p, vector<double>& q) {
        p.assign(n + 1, 0.0);
        q.assign(n + 1, 0.0);
        for (int i = 1; i <= n; i++) {
            if (type == 1) p[i] = 10.0; // Uniform
            else if (type == 2) p[i] = i * 1.0; // Ascending
            else if (type == 3) p[i] = (n - i + 1) * 1.0; // Descending
            else if (type == 4) p[i] = (n / 2.0) - abs((n / 2.0) - i) + 1; // Bell Curve (Center Heavy)
        }
        for (int i = 0; i <= n; i++) {
            q[i] = (type == 1) ? 5.0 : (rand() % 10) + 1; // Small random gaps or uniform gaps
        }
        normalize(n, p, q);
    };

    vector<double> p, q;

    // Test Case 1: Uniform distribution (N = 100)
    gen_pattern(100, 1, p, q);
    execute(1, p, q);

    // Test Case 2: Ascending distribution (N = 100)
    gen_pattern(100, 2, p, q);
    execute(2, p, q);

    // Test Case 3: Descending distribution (N = 100)
    gen_pattern(100, 3, p, q);
    execute(3, p, q);

    // Test Case 4: Bell Curve / Center Heavy distribution (N = 100)
    gen_pattern(100, 4, p, q);
    execute(4, p, q);
    gen_pattern(1000, 4, p, q);
    execute(4, p, q);

    // Test Case 5: Fully Random Probabilities (N = 100)
    gen_random(100, p, q);
    execute(5, p, q);

    // Test Case 6: Fully Random Probabilities (N = 150)
    gen_random(150, p, q);
    execute(6, p, q);
    gen_random(1500, p, q);
    execute(6, p, q);

    // Test Case 7: Fully Random Probabilities (N = 200)
    gen_random(200, p, q);
    execute(7, p, q);
    gen_random(1800, p, q);
    execute(7, p, q);

    // Test Case 8: Bell Curve / Center Heavy distribution (N = 200)
    gen_pattern(200, 4, p, q);
    execute(8, p, q);
    gen_pattern(2000, 4, p, q);
    execute(8, p, q);

    return 0;
}