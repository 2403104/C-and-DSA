#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination) {
    if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
        return -1;
    if (source == destination) return 0;

    int n = grid.size(), m = grid[0].size();
    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};

    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});

    while (!q.empty()) {
        auto it = q.front();
        int distance = it.first;
        int r = it.second.first;
        int c = it.second.second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int newR = r + dx[i];
            int newC = c + dy[i];

            if (newR >= 0 && newR < n && newC >= 0 && newC < m && grid[newR][newC] == 1 && distance + 1 < dist[newR][newC]) {
                if (newR == destination.first && newC == destination.second) 
                    return distance + 1;

                dist[newR][newC] = distance + 1;
                q.push({distance + 1, {newR, newC}});
            }
        }
    }
    return -1;
}

int main() {
    int n = 5, m = 5;
    vector<vector<int>> grid = {
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 1, 1},
        {1, 0, 1, 1, 0},
        {1, 1, 1, 0, 1}
    };
    pair<int, int> source = {0, 0};
    pair<int, int> destination = {3,3};

    int result = shortestPath(grid, source, destination);
    if (result != -1) {
        cout << "Shortest path length: " << result << endl;
    } else {
        cout << "No path exists." << endl;
    }

    return 0;
}
