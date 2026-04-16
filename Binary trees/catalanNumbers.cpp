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
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        val=val;
        left=NULL;
        right=NULL;
    }
};
vector<TreeNode*> constructTrees(int st,int en){
    vector<TreeNode*> trees;
    if(st>en){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=st;i<=en;i++){
        vector<TreeNode*>leftSub=constructTrees(st,i-1);
        vector<TreeNode*>rightSub=constructTrees(i+1,en);
        for(int j=0;j<leftSub.size();j++){
            TreeNode* left=leftSub[j];
            for(int k=0;k<rightSub.size();k++){
                TreeNode* right=rightSub[k];
                TreeNode* node=new TreeNode(i);
                node->left=left;
                node->right=right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}
int catalan(int n){
    vi dp(n+1,0);
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        int cat=0;
        for(int j=0;j<i;j++){
            cat+=dp[j]*dp[i-j-1];
        }
        dp[i]=cat;
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr); 
    #endif
    for(int i=0;i<=5;i++) cout<<catalan(i)<<endl;
    

    return 0;
}
/*
Catalan Numbers Explanation
---------------------------

Definition:
-----------
The Catalan numbers are a sequence of natural numbers that have many applications in combinatorial mathematics.

The nth Catalan number is given by:

        Cn = (1 / (n + 1)) * (2n choose n)
           = (2n)! / ((n + 1)! * n!)

Properties:
-----------
1) C0 = 1
2) Recurrence relation:
       Cn+1 = Σ (Ci * Cn-i) for i = 0 to n

Applications:
-------------
1) Number of valid parentheses expressions of length 2n.
2) Number of ways to completely parenthesize n+1 factors.
3) Number of possible binary search trees with n nodes.
4) Number of ways to triangulate a convex polygon with n+2 sides.
5) Number of non-crossing partitions of a set.
6) Number of ways to connect 2n points on a circle with n non-crossing chords.

Examples:
---------
C0 = 1
C1 = 1
C2 = 2
C3 = 5
C4 = 14
C5 = 42
...

Computation:
------------
Using Recurrence:
    Cn+1 = Σ (Ci * Cn-i) for i = 0 to n

Using Formula:
    Cn = (2n)! / ((n + 1)! * n!)

Code Example (C++):
-------------------
const int MOD = 1e9+7;
vector<ll> catalan(int n) {
    vector<ll> cat(n+1, 0);
    cat[0] = cat[1] = 1;
    for(int i=2; i<=n; i++) {
        for(int j=0; j<i; j++) {
            cat[i] = (cat[i] + cat[j]*cat[i-j-1]) % MOD;
        }
    }
    return cat;
}

Time Complexity: O(n^2)
Space Complexity: O(n)


*/