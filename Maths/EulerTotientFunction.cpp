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
const int N=1e5+2;
int totient[N];

void solve(){
    for(int i=1;i<11;i++) cout<<totient[i]<<endl;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr); 
    #endif
    for(int i=0;i<=N;i++) totient[i]=i;
    for(int i=2;i<N;i++){
        if(totient[i]==i){
            for(int j=2*i;j<N;j+=i){
                totient[i]=(totient[i]*(i-1))/i;
            }
            totient[i]=i-1; 
        }
    }
    int t;
    // cin>>t;
    t=1;
    while(t--){
        solve();
    }

    return 0;
}
/*
Euler's Totient Function (φ(n)):

Definition:
φ(n) is defined as the number of positive integers less than or equal to n that are coprime with n.
Two numbers are coprime if their greatest common divisor (GCD) is 1.

Examples:
- φ(1) = 1  (only 1 is coprime with itself)
- φ(2) = 1  (1 is coprime with 2)
- φ(3) = 2  (1 and 2 are coprime with 3)
- φ(4) = 2  (1 and 3 are coprime with 4)
- φ(5) = 4  (1, 2, 3, 4 are coprime with 5)

Properties:
1. If p is a prime number, then:
   φ(p) = p - 1
   (All numbers from 1 to p-1 are coprime with p)

2. If p is a prime and k ≥ 1, then:
   φ(p^k) = p^k - p^(k-1)

3. For any two positive integers a and b such that gcd(a, b) = 1:
   φ(a * b) = φ(a) * φ(b)   (Euler’s Totient function is multiplicative)

Formula using prime factorization:
Let n = p1^a1 * p2^a2 * ... * pk^ak (prime factorization of n)
Then:
φ(n) = n * (1 - 1/p1) * (1 - 1/p2) * ... * (1 - 1/pk)

Example:
Let n = 10
Prime factorization: 10 = 2 * 5
φ(10) = 10 * (1 - 1/2) * (1 - 1/5) = 10 * (1/2) * (4/5) = 4

Applications:
- Used in Euler's Theorem: a^φ(n) ≡ 1 mod n when gcd(a, n) = 1
- Important in number theory and cryptography (e.g., RSA algorithm)

*/