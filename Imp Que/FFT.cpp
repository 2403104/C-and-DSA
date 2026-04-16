#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define input(arr) for(auto &it : arr) cin >> it;
#define output(arr) do { for (auto &it : arr) cout << it << ' '; cout << endl; } while(0);
const double PI = acos(-1);
class Complex {
public:
    double a, b;
    Complex(double a = 0, double b = 0) : a(a), b(b) {}

    Complex operator+(const Complex &other) {
        return Complex(a + other.a, b + other.b);    
    }

    Complex operator-(const Complex &other) {
        return Complex(a - other.a, b - other.b);    
    }

    Complex operator*(const Complex &other) {
        return Complex(a * other.a - b * other.b, a * other.b + b * other.a);    
    }
};

vector<Complex> rec_fft(vector<Complex> &a) {
    int n = a.size();
    if(n == 1)  return a;
    vector<Complex> A0, A1;

    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            A0.push_back(a[i]);
        } else {
            A1.push_back(a[i]);
        }
    }

    A0 = rec_fft(A0);
    A1 = rec_fft(A1);

    vector<Complex> res(n);

    Complex W(cos(2 * PI / n), sin(2 * PI / n));
    Complex w(1);

    for(int i = 0; i < n / 2; i++) {
        res[i] = A0[i] + w * A1[i];
        res[i + n / 2] = A0[i] - w * A1[i];
        w = w * W;
    }

    return res;
}
vector<int> rev;
void reverseBits(int &n){
    int len = 0;
    while(1 << len < n) len++;
    int N = 1 << len;
    rev.resize(N, 0);
    for(int i = 1; i < N; i++) {
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
    }
}
vector<Complex> nonrec_fft(vector<Complex> &a) {
    int n = a.size();

    for(int i = 0; i < n; i++) {
        if(i < rev[i]) swap(a[i], a[rev[i]]);
    }

    Complex W(cos(2 * PI / n), sin(2 * PI / n));

    for(int len = 2; len <= n; len <<= 1){
        for(int j = 0; j < n; j += len){
            Complex w(1);
            for(int k = 0; k < len / 2; k++){
                Complex u = a[j + k];
                Complex v = a[j + k + len / 2] * w;
                a[j + k] = u + v;
                a[j + k + len / 2] = u - v;
                w = w * W;
            }
        }
    }
    return a;
}

vector<Complex> inverse_fft(vector<Complex> &a) {
    int n = a.size();
    vector<Complex> res = rec_fft(a);
    reverse(res.begin() + 1, res.end());
    for(int i = 0; i < n; i++) {
        res[i].a = res[i].a / n;
        res[i].b = res[i].b / n;
    }
    return res;
}

vector<Complex> multiplyRec(vector<Complex> &a, vector<Complex> &b) {
    int n = a.size();
    int m = b.size();

    int N = n + m - 1;

    int nP = 1;
    while(nP < N) nP <<= 1;

    a.resize(nP);
    b.resize(nP);

    a = rec_fft(a);
    b = rec_fft(b);

    vector<Complex> res(nP);

    for(int i = 0; i < nP; i++) {
        res[i] = a[i] * b[i];
    }

    vector<Complex> inverse = inverse_fft(res);

    return inverse;
}

vector<Complex> multiplyNonRec(vector<Complex> &a, vector<Complex> &b) {
    int n = a.size();
    int m = b.size();

    int N = n + m - 1;

    reverseBits(N);

    a.resize(N);
    b.resize(N);

    a = nonrec_fft(a);
    b = nonrec_fft(b);

    vector<Complex> res(N);

    for(int i = 0; i < N; i++) {
        res[i] = a[i] * b[i];
    }

    vector<Complex> inverse = inverse_fft(res);

    return inverse;
}

int main(){
    vector<Complex> a = {1, 2, 3};
    vector<Complex> b = {4, 5};

    int n = a.size();
    int m = b.size();

    vector<Complex> a1 = a, b1 = b;
    vector<Complex> a2 = a, b2 = b;

    vector<Complex> res1 = multiplyRec(a1, b1);
    vector<Complex> res2 = multiplyNonRec(a2, b2);


    for (int i = 0; i < n + m - 1; i++) {
        cout << (long long)(res1[i].a + 0.5) << " ";
    }
    cout << endl;

    for (int i = 0; i < n + m - 1; i++) {
        cout << (long long)(res2[i].a + 0.5) << " ";
    }
    cout << endl;
    
    return 0;
}