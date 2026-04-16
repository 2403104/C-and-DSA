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
//ax + by= gcd(a,b)
//ax+by=c gcd(a,b) divides c
struct triplet{
    int x, y , gcd;
};
int gcd(int a, int b){ 
    if(b==0) return a;
    return gcd(b,a%b);
}
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
    int a,b;
    cin>>a>>b;
    triplet ans=extendedEuclid(a,b);
    cout<<ans.x<<" "<<ans.y<<endl;
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
DIAPHANTINE EQUATIONS EXPLAINED
-------------------------------

1. What is a Diophantine Equation?

A Diophantine Equation is an equation that allows only integer solutions. 
The coefficients of the equation and the solution must be integers.

General form: 
    f(x1, x2, ..., xn) = 0, where solutions must be integers.

Example:
    3x + 5y = 7  (Find integer pairs (x, y) that satisfy this)

--------------------------------------------

2. Linear Diophantine Equation

Form:
    ax + by = c

Where:
- a, b, c are integers
- We seek integer solutions (x, y)

Existence of Solution:
- A solution exists if and only if gcd(a, b) divides c.

Example:
    6x + 9y = 30
    gcd(6, 9) = 3, and 3 divides 30 ⇒ Solutions exist.

General Solution:
- Let d = gcd(a, b)
- Use Extended Euclidean Algorithm to find one solution (x0, y0)
- Then, all solutions are of the form:
    x = x0 + (b/d)t
    y = y0 - (a/d)t
    where t is any integer

--------------------------------------------

3. Extended Euclidean Algorithm (EEA)

EEA finds integers x and y such that:
    ax + by = gcd(a, b)

This helps in solving Diophantine equations.

Example:
    Solve 15x + 20y = 100

    Step 1: gcd(15, 20) = 5
    Step 2: 5 divides 100 ⇒ Solutions exist
    Step 3: Use EEA to get (x0, y0) such that 15x + 20y = 5
    Multiply both x0 and y0 by 20 to get solution to original equation

--------------------------------------------

4. Applications

- Solving puzzles with constraints
- Cryptography (e.g., RSA)
- Modular arithmetic
- Competitive programming problems

--------------------------------------------

5. Key Points

- Always check gcd(a, b) divides c
- Use Extended Euclidean Algorithm to get one solution
- Use general solution formula to generate more solutions


*/