#include <bits/stdc++.h>
using namespace std;

unordered_map<int, pair<int, int>> mp;
map<int, vector<vector<pair<int, int>>>> paths;
int maxi=0;

void findAllPaths(vector<vector<char>>& mat, vector<vector<bool>>& vis, int stI, int stJ, int enI, int enJ, int i, int j, vector<pair<int, int>>& curr) {
    int r = mat.size(), c = mat[0].size();
    if (i < 0 || i >= r || j < 0 || j >= c || vis[i][j]) return;
    if (isdigit(mat[i][j]) && !(i == stI && j == stJ) && !(i == enI && j == enJ)) return;

    curr.push_back({i, j});
    vis[i][j] = true;

    if (i == enI && j == enJ) {
        int sum = (mat[stI][stJ] - '0') + (mat[enI][enJ] - '0');
        paths[sum].push_back(curr);
    } else {
        findAllPaths(mat, vis, stI, stJ, enI, enJ, i + 1, j, curr);
        findAllPaths(mat, vis, stI, stJ, enI, enJ, i - 1, j, curr);
        findAllPaths(mat, vis, stI, stJ, enI, enJ, i, j + 1, curr);
        findAllPaths(mat, vis, stI, stJ, enI, enJ, i, j - 1, curr);
    }

    curr.pop_back();
    vis[i][j] = false;
}

bool fillPathsWithStar(vector<vector<char>>& mat, int sum) {
    vector<vector<char>>cpy=mat;
    if (sum > maxi+maxi-1) return true; 

    if (paths.find(sum) == paths.end()) return false;

    for (auto& path : paths[sum]) {
        bool valid = true;
        for (auto& cell : path) {
            int x = cell.first, y = cell.second;
            if (mat[x][y] == '*') {
                valid = false;
                break;
            }
        }
        
        if (!valid) continue;

        vector<pair<int, int>> modified;
        for (auto& cell : path) {
            int x = cell.first, y = cell.second;
            if (mat[x][y] == ' ') {
                mat[x][y] = '*';
                modified.push_back(cell);
            }
        }

        if (fillPathsWithStar(mat, sum + 2)) return true;

        for (auto& cell : modified) {
            mat[cell.first][cell.second] = cpy[cell.first][cell.second];
        }
    }

    return false;
}


int main() {
    vector<vector<char>> mat = {
        {' ', '2', ' ', ' ', ' ',' ','6'},
        {' ', ' ', ' ', ' ', ' ',' ',' '},
        {' ', ' ', ' ', '1', ' ','7',' '},
        {' ', ' ', ' ', ' ', ' ',' ',' '},
        {' ', ' ', ' ', ' ', ' ','3',' '},
        {'4', ' ', ' ', ' ', ' ',' ','5'}
    };

    int r = mat.size(), c = mat[0].size();

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (isdigit(mat[i][j])) {
                maxi=max(maxi,(int)mat[i][j]-'0');
                mp[mat[i][j] - '0'] = {i, j};
            }
        }
    }

    for (int i = 1; mp.find(i + 1) != mp.end(); i++) {
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        vector<pair<int, int>> curr;
        auto start = mp[i], end = mp[i + 1];
        findAllPaths(mat, vis, start.first, start.second, end.first, end.second, start.first, start.second, curr);
    }
    for (auto& it : paths) {
        sort(it.second.begin(), it.second.end(), [](const vector<pair<int, int>>& a, const vector<pair<int, int>>& b) {
            return a.size() < b.size();
        });
    }
    
    fillPathsWithStar(mat, 3);
    for (auto& row : mat) {
        for (auto& ch : row) {
            cout << ch <<' ';
        }
        cout << '\n';
    }

    return 0;
}
