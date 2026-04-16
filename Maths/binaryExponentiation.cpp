#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int MOD = (int)(1e9 + 7);
struct Matrix {
    int n;
    vector<vector<long long>> mat;
    Matrix(int size) {  
        n = size;
        mat.assign(n, vector<long long>(n, 0));
    }
    static Matrix identity(int size) {
        Matrix res(size);
        for (int i = 0; i < size; i++) {
            res.mat[i][i] = 1;
        }
        return res;
    }
    Matrix operator*(const Matrix& other) const {
        Matrix res(n);
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (mat[i][k] == 0) continue;                
                for (int j = 0; j < n; j++) {
                    res.mat[i][j] = (res.mat[i][j] + mat[i][k] * other.mat[k][j]) % MOD;
                }
            }
        }
        return res;
    }
};
Matrix matrix_exponentiation(Matrix base, long long e) {
  Matrix res = Matrix::identity(base.n);
  while(e) {
    if(e & 1) res = res * base;
    base = base * base;
    e >>= 1;
  }
  return res;
}

int main(){
  
  return 0;
}