#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define input(arr) for(auto &it : arr) cin>>it;
#define pb push_back
#define p push
#define F first
#define S second
typedef std::vector<int> vi;
typedef std::vector<long long> vl;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
struct triplet{
    int x, y , gcd;
};
triplet extendedEuclid(int a, int b){
    if(b==0){
        triplet base;
        base.x=1;
        base.y=0;
        base.gcd=a;
        return base;
    }
    triplet smallAns=extendedEuclid(b,a%b);
    triplet ans;
    ans.x=smallAns.y;
    ans.y=  smallAns.x-(a/b)*smallAns.y;
    ans.gcd=smallAns.gcd;
    return ans;
}
void solve(){
    int A,mod;
    cin>>A>>mod;
    //(A*B)%mod=1
    //B = value of B will be equal to the value of x in diophantine equation in A, mod
    int B=extendedEuclid(A,mod).x;
    cout<<(B%mod+mod)%mod<<endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr); 
    #endif

    int t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }

    return 0;
}

/*
# Multiplicative Modulo Inverse

## Definition:

The multiplicative modulo inverse of an integer `a` modulo `m` is an integer `x` such that:

```
(a * x) ≡ 1 (mod m)
```

That means: the remainder when `a * x` is divided by `m` is 1.

## Existence:

The inverse exists **only if gcd(a, m) == 1**, i.e., `a` and `m` are coprime.

## Methods to Compute:

1. Brute-force (only for small `m`):

   * Try all values of `x` from 1 to m-1
   * Check if `(a * x) % m == 1`

2. Extended Euclidean Algorithm:

   * It solves `ax + my = gcd(a, m)`
   * If gcd is 1, then `x` is the modular inverse
   * Make sure result is positive:

     x = (x % m + m) % m

3. Fermat's Little Theorem (when m is prime):

   * If `m` is prime and `gcd(a, m) == 1`, then:

     a^(m-2) ≡ a^(-1) (mod m)

   * Use fast exponentiation to compute:

     inverse = binpow(a, m - 2, m)

   * Example of binary exponentiation in C++:

     long long binpow(long long a, long long b, long long m) {
     long long res = 1;
     a %= m;
     while (b > 0) {
     if (b & 1)
     res = res \* a % m;
     a = a \* a % m;
     b >>= 1;
     }
     return res;
     }

## Applications:

* Useful in modular division
* Solving linear congruences
* Inverse factorials in combinatorics
* Competitive programming modulo problems

*/