/*
Sparse Table Construction Explanation
====================================

We build a 2D array st[i][j] where:

- 'i' is the starting index of the interval.
- 'j' means the length of the interval is 2^j.
- st[i][j] stores the minimum value in the subarray arr[i .. i + 2^j - 1].

The goal is to precompute the minimum values for all intervals of size 2^0, 2^1, 2^2, ..., up to the largest power of 2 ≤ n.

Level 0: Length 1 = 2^0
------------------------
st[i][0] = arr[i]
This simply initializes the first level of the table with the original array values.

Level 1: Length 2 = 2^1
------------------------
st[i][1] = min(st[i][0], st[i+1][0])
         = min(arr[i], arr[i+1])
This combines two elements to get the minimum over a subarray of length 2.

Level 2: Length 4 = 2^2
------------------------
st[i][2] = min(st[i][1], st[i+2][1])
         = min(
             min(arr[i], arr[i+1]),
             min(arr[i+2], arr[i+3])
           )
         = min(arr[i], arr[i+1], arr[i+2], arr[i+3])
This combines two length-2 intervals to get the minimum over a subarray of length 4.

Level 3: Length 8 = 2^3
------------------------
st[i][3] = min(st[i][2], st[i+4][2])
         = min(arr[i] to arr[i+7])
This pattern continues for all higher powers of two.

General Formula
---------------
st[i][j] = min(st[i][j-1], st[i + 2^(j-1)][j-1])
This formula uses two overlapping intervals of length 2^(j-1) to compute the interval of length 2^j.

Querying the Minimum in Range [L, R]
------------------------------------
To find the minimum in the range arr[L..R]:

1. Compute length = R - L + 1
2. Let k = floor(log2(length))
3. Answer = min(st[L][k], st[R - 2^k + 1][k])

This works because two overlapping intervals of size 2^k can fully cover any interval of length ≤ 2^k + (extra part).

Time and Space Complexity
-------------------------
Preprocessing Time: O(n log n)
Query Time: O(1)
Space: O(n log n)
Only works for idempotent operations like min, max, gcd.

logTable is used to calculate the log of length
log2(i) = 1 + log2(i/2)
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXM=1e5+5;
const int LOG=19;
int st[MAXM][LOG];
int logTable[MAXM];
void computeLogs(int n){
    logTable[1]=0;
    for(int i=2;i<=n;i++){
        logTable[i]=logTable[i/2]+1;//log2(i) = 1 + log2(i/2)
    }
}
void buildSparseTable(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        st[i][0]=arr[i];
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;i+(1<<j)<=n;i++){
            st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
}
int query(int L , int R){
    int len=R-L+1;
    int k=logTable[len];
    return min(st[L][k],st[R-(1<<k)+1][k]);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr); 
    #endif
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    computeLogs(n);
    buildSparseTable(arr,n);
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << "\n";
    }

    return 0;
}