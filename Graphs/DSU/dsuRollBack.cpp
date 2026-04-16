#include<bits/stdc++.h>
using namespace std;
/*
childRoot: The root that gets attached under the other root during union.
oldParent: The parent of "childRoot" before the union happened.
*/
class RollbackDSU{
    vector<int> rank, parent;
    stack<tuple<int, int, int>> history; // {childRoot, oldParent, didRankInc}
public:
    RollbackDSU(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int node){
        if(node == parent[node]) return node;
        return find(parent[node]);
    }
    void unionByRank(int u, int v){ 
        int ulpU = find(u);
        int ulpV = find(v);
        if(ulpU == ulpV) {
            history.push({-1, -1, -1});
            return;
        }
        int inc = 0;
        int chRoot;
        int oldPar;
        if(rank[ulpU] < rank[ulpV]) {
            parent[ulpU] = ulpV;
            chRoot = oldPar = ulpU;
        }
        else if(rank[ulpU] > rank[ulpV]) {
            parent[ulpV] = ulpU;
            chRoot = oldPar = ulpV;
        }
        else {
            parent[ulpV] = ulpU;
            rank[ulpU]++;
            inc = 1;
            chRoot = oldPar = ulpV;
        }
        history.push({chRoot, oldPar, inc});
    }
    void rollback(){
        if(history.empty()) return;
        auto [childRoot, oldParent, didRankInc] = history.top(); history.pop();
        if(childRoot == -1) return ;
        int newPar = parent[childRoot];
        parent[childRoot] = oldParent;
        if(didRankInc){
            rank[newPar]--;
        }
    }
};
int main(){
    RollbackDSU dsu(7);

    dsu.unionByRank(1, 2);
    dsu.unionByRank(2, 3);
    dsu.unionByRank(4, 5);
    dsu.unionByRank(3, 5);

    cout << "Root of 5 after unions: " << dsu.find(5) << "\n";

    dsu.rollback();
    cout << "Root of 5 after 1st rollback: " << dsu.find(5) << "\n";

    dsu.rollback();
    cout << "Root of 5 after 2nd rollback: " << dsu.find(5) << "\n";


    return 0;
}