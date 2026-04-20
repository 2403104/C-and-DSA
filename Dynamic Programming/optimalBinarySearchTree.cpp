#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int main(){
  vector<double> p = {0.15, 0.10, 0.05, 0.10, 0.20};
  vector<double> q = {0.05, 0.10, 0.05, 0.05, 0.05, 0.10};

  int n = (int)p.size();
  std::vector<std::vector<double>> E(n + 2, std::vector<double>(n + 1, 0.0));
  std::vector<std::vector<double>> W(n + 2, std::vector<double>(n + 1, 0.0));

  for(int i = 1; i <= n; i++) {
    E[i][i - 1] = q[i - 1];
    W[i][i - 1] = q[i - 1];
  }

  for(int len = 1; len <= n; len++) {
    for(int i = 1; i + len - 1 <= n; i++) {
      int j = i + len - 1;
      E[i][j] = DBL_MAX;
      W[i][j] = W[i][j - 1] + p[j - 1] + q[j];
      for(int r = i; r <= j; r++) {
        double curr = E[i][r - 1] + E[r + 1][j] + W[i][j];
        if(curr < E[i][j]) E[i][j] = curr;
      }
    }
  }

  std::cout << fixed << setprecision(10) << E[1][n] << "\n";
  
  return 0;
}