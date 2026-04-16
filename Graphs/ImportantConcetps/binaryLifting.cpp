#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1e5 + 1;
vector<int> tree[N];
int up[N][20];

void binaryLifting(int src, int par) {
    up[src][0] = par;
    for (int i = 1; i <= 19; i++) {
        if (up[src][i - 1] != -1) {
            up[src][i] = up[up[src][i - 1]][i - 1];
        } else {
            up[src][i] = -1;
        }
    }
    for (int child : tree[src]) {
        if (child != par) binaryLifting(child, src);
    }
}
int ansQuery(int node, int jump){
    if(node==-1 || jump==0) return node;
    for(int i=19;i>=0;i--){
        if(jump>=(i<<i)){ // better use & (jump & (1 << i))
            return ansQuery(up[node][i],jump-(1<<i));
        }
    }
}
int main() {
    int n = 9;
    
    vector<pair<int, int>> edges = {
        {1, 2},
        {1, 3},
        {2, 4},
        {2, 5},
        {3, 6},
        {3, 7},
        {6, 8},
        {6, 9}
    };

    for (auto it : edges) {
        int u=it.first;
        int v=it.second;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(up, -1, sizeof(up)); 
    binaryLifting(1, -1);

    for (int i = 0; i <= 4; i++) {
        cout << up[8][i] << " ";
    }
    cout << endl;

    return 0;
}
