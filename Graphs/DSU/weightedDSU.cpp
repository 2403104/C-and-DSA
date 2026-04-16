#include<bits/stdc++.h>
using namespace std;
class WeightedDSU{
    vector<int> rank, parent, weight;
public:
    WeightedDSU(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        weight.resize(n + 1, 0);
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    pair<int,int> find(int node){ //{root, value(node) - value(root)}
        if(node == parent[node]){
            return {node, 0};
        }
        int curr = weight[node];
        auto it = find(parent[node]);
        parent[node] = it.first;
        weight[node] += it.second;
        return {parent[node], weight[node]};
    }
    void unionByRank(int u, int v, int wt){ // (u) --(wt)--> (v)
        auto [ulpU, wtU] = find(u);
        auto [ulpV, wtV] = find(v);
        if(ulpU == ulpV) return ;
        if(rank[ulpU] < rank[ulpV]){
            parent[ulpU] = ulpV;
            int x = wtV - wt - wtU;
            weight[ulpU] = x;
        }else if(rank[ulpU] > rank[ulpV]){
            parent[ulpV] = ulpU;
            int x = wtU + wt - wtV;
            weight[ulpV] = x;
        }else{
            parent[ulpU] = ulpV;
            rank[ulpV]++;
            int x = wtV - wt - wtU;
            weight[ulpU] = x;            
        }
    }
    int diff_uv(int u, int v){
        auto [pu, d1] = find(u);
        auto [pv, d2] = find(v);
        if(pu != pv) return INT_MAX;
        return d2 - d1;
    }
};
int main(){
    WeightedDSU dsu(5);

    // value(2) - value(1) = 3
    dsu.unionByRank(1, 2, 3);

    // value(3) - value(2) = 5
    dsu.unionByRank(2, 3, 5);

    // value(5) - value(4) = 7
    dsu.unionByRank(4, 5, 7);

    cout << "diff(1,2) = " << dsu.diff_uv(1,2) << endl; // 3 
    cout << "diff(2,3) = " << dsu.diff_uv(2,3) << endl; // 5 
    cout << "diff(1,3) = " << dsu.diff_uv(1,3) << endl; // 8 
    cout << "diff(3,1) = " << dsu.diff_uv(3,1) << endl; // -8
    cout << "diff(4,5) = " << dsu.diff_uv(4,5) << endl; // 7 

    int res = dsu.diff_uv(1,5);
    if(res == INT_MAX)
        cout << "1 and 5 are NOT connected\n";
    else
        cout << "diff(1,5) = " << res << endl;

    return 0;
}