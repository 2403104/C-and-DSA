#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> subtree_size;
int total_nodes;

void dfs_size(int u, int p) {
    subtree_size[u] = 1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs_size(v, u);
            subtree_size[u] += subtree_size[v];
        }
    }
}

int find_centroid_dfs(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            if (subtree_size[v] > total_nodes / 2) {
                return find_centroid_dfs(v, u);
            }
        }
    }
    return u;
}

vector<int> get_centroids(int n, int root = 1) {
    adj.assign(n + 1, vector<int>());
    subtree_size.assign(n + 1, 0);
    total_nodes = n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs_size(root, 0);
    int c1 = find_centroid_dfs(root, 0);
    vector<int> centroids;
    centroids.push_back(c1);
    int max_subtree_c1 = total_nodes - subtree_size[c1];
    for (int v : adj[c1]) {
        if (subtree_size[v] > max_subtree_c1) {
            max_subtree_c1 = subtree_size[v];
        }
    }
    for (int v : adj[c1]) {
        if (subtree_size[v] == total_nodes / 2) {
            centroids.push_back(v);
        }
    }
    return centroids;
}

int main() {
    int n;
    cout << "Enter the number of nodes in the tree: ";
    cin >> n;
    cout << "Enter the edges (u, v):" << endl;
    vector<int> centroids = get_centroids(n);
    cout << "The centroid(s) of the tree are: ";
    for (int i = 0; i < centroids.size(); ++i) {
        cout << centroids[i] << (i == centroids.size() - 1 ? "" : " ");
    }
    cout << endl;
    return 0;
}
