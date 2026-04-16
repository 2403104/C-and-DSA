#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.assign(n + 1, 0);
        size.assign(n + 1, 1);
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    int findParent(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulpU = findParent(u);
        int ulpV = findParent(v);
        if(ulpU == ulpV) return;
        if(rank[ulpU] < rank[ulpV]) {
            parent[ulpU] = ulpV;
        }
        else if(rank[ulpU] > rank[ulpV]) {
            parent[ulpV] = ulpU;
        }
        else {
            parent[ulpV] = ulpU;
            rank[ulpU]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulpU = findParent(u);
        int ulpV = findParent(v);
        if(ulpU == ulpV) return;
        if(size[ulpU] < size[ulpV]) {
            parent[ulpU] = ulpV;
            size[ulpV] += size[ulpU];
        }
        else if(size[ulpU] > size[ulpV]) {
            parent[ulpV] = ulpU;
            size[ulpU] += size[ulpV];
        }
        else {
            parent[ulpV] = ulpU;
            size[ulpU] += size[ulpV];
        }
    }
};

int main() {
    DisjointSet dsu(7);

    dsu.unionByRank(1,2);
    dsu.unionByRank(2,3);
    dsu.unionByRank(4,5);
    dsu.unionByRank(6,7);
    dsu.unionByRank(5,6);

    cout << dsu.findParent(3) << "\n";
    cout << dsu.findParent(7) << "\n";
    cout << dsu.findParent(1) << "\n";

    return 0;
}
