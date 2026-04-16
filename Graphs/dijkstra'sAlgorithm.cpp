/*
Dijkstra's Algorithm with both priority_queue and set versions

Use Case:
Find the shortest distance from a source node to all other nodes in a weighted graph with non-negative edges.

Approach:
- Maintain a min-heap (priority_queue or set) to always choose the next closest node.
- Use an adjacency list to store the graph.

Differences:
1. priority_queue:
    - Standard C++ min-heap (with custom comparison via greater<>).
    - Might add duplicate entries, so we check if a shorter path was already found.
    - Faster for dense graphs.

2. set:
    - Ordered set stores {distance, node}.
    - Automatically removes duplicates and allows efficient updates (by erasing old entries).
    - Useful when needing to remove and update nodes with specific values.

Time Complexity: O((V + E) * log V)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra_pq(int n, vector<vector<pair<int, int>>>& graph, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        auto it = pq.top(); pq.pop();
        auto d=it.first;
        auto u=it.second;
        if (d > dist[u]) continue;// has already been processed
        for (auto neb : graph[u]) {
            auto v=neb.first;
            auto w=neb.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

vector<int> dijkstra_set(int n, vector<vector<pair<int, int>>>& graph, int src) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    // Set automatically keeps the smallest distance at the beginning
    set<pair<int, int>> st;
    st.insert({0, src});

    while (!st.empty()) {
        auto [d, u] = *st.begin();
        st.erase(st.begin());

        for (auto [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                if (dist[v] != INT_MAX) {//it has been already processed
                    st.erase({dist[v], v});
                }
                dist[v] = dist[u] + w;
                st.insert({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    vector<vector<pair<int, int>>> graph(n);

    // Undirected graph
    graph[0].push_back({1, 2});
    graph[1].push_back({0, 2});

    graph[0].push_back({2, 4});
    graph[2].push_back({0, 4});

    graph[1].push_back({2, 1});
    graph[2].push_back({1, 1});

    graph[1].push_back({3, 7});
    graph[3].push_back({1, 7});

    graph[2].push_back({4, 3});
    graph[4].push_back({2, 3});

    int source = 0;

    cout << "Using priority_queue:\n";
    vector<int> dist1 = dijkstra_pq(n, graph, source);
    for (int i = 0; i < n; ++i)
        cout << "To node " << i << ": " << dist1[i] << '\n';

    cout << "\nUsing set:\n";
    vector<int> dist2 = dijkstra_set(n, graph, source);
    for (int i = 0; i < n; ++i)
        cout << "To node " << i << ": " << dist2[i] << '\n';

    return 0;
}
