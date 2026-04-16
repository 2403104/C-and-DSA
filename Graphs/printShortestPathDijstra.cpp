#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (ll i = a; i < b; ++i)
#define per(i, b, a) for (ll i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define F first
#define S second
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;

const ll INF = 1e18;

vvl dijkstra(ll n, vector<vector<ll>> &edges, ll src, vl &dist) {
    vector<vector<pll>> graph(n);
    for (auto &it : edges) {
        graph[it[0]].push_back({it[1], it[2]});
        graph[it[1]].push_back({it[0], it[2]});
    }

    dist.assign(n, INF);
    vvl store(n);
    for (ll i = 0; i < n; i++) store[i].push_back(i);

    dist[src] = 0;
    priority_queue<pll, vector<pll>, greater<>> pq; // {dist,node}
    pq.push({0, src});

    while (!pq.empty()) {
        ll d = pq.top().F;
        ll node = pq.top().S;
        pq.pop();

        if (d > dist[node]) continue;

        for (auto &it : graph[node]) {
            ll next = it.F;
            ll wt = it.S;
            if (dist[next] > d + wt) {
                dist[next] = d + wt;
                store[next] = store[node];
                store[next].push_back(next);
                pq.push({dist[next], next});
            }
        }
    }

    return store;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> edges(m, vector<ll>(3));
    for (ll i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][0]--; 
        edges[i][1]--;
    }

    vl dist;
    vvl store = dijkstra(n, edges, 0, dist);

    if (dist[n - 1] == INF) {
        cout << -1 << '\n';
    } else {
        for (auto node : store[n - 1]) cout << node + 1 << ' '; 
        cout << '\n';
    }

    return 0;
}
