#include <bits/stdc++.h>
using namespace std;
/*
Relaxing an edge means:

Checking if we can improve the shortest known distance to a node by taking a
 specific edge. If yes, we update it.
*/
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define p push
#define F first
#define S second
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;

class Solution {
  public:
    const int big=1e8;
    vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
        vi dist(n,big);
        dist[src]=0;
        rep(i,0,n-1){
            for(auto it : edges){
                int node1=it[0];
                int node2=it[1];
                int wt=it[2];
                if(dist[node1]!=big &&  dist[node1]+wt<dist[node2]){
                    dist[node2]=wt+dist[node1];
                }
            }
        }
        for(auto it : edges){
            int node1=it[0];
            int node2=it[1];
            int wt=it[2];
            if (dist[node1] != big && dist[node1] + wt < dist[node2]) {
                return {-1};
            }
        }
        return dist;
    }
};
/*
Use Bellman-Ford when:
The graph has negative weight edges.
You need to detect negative cycles.

Use Dijkstra's when:
All edges have non-negative weights.
Efficiency is more important than handling negative weights.

A negative cycle in a graph is a cycle (a path that starts and ends at the same vertex) 
where the sum of the edge weights is negative.

🔍 Key Points about Negative Cycles:
A negative cycle allows you to keep reducing the path cost indefinitely by going around the cycle repeatedly.
In shortest path problems, a negative cycle means there is no shortest path with a finite cost — you can keep reducing the path length infinitely by traversing the cycle again and again.
*/