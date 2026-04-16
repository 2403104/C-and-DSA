# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;

void dfs(vector<vector<int>>&grid, int i, int j, int r, int c){
    if(i<0 || i>=r || j<0 || j>=c || grid[i][j]==0) return;
    grid[i][j]=0;
    dfs(grid, i+1,j,r,c);
    dfs(grid, i-1,j,r,c);
    dfs(grid, i,j+1,r,c);
    dfs(grid, i,j-1,r,c);
}

int numIslands(vector<vector<int>>& grid) {
    int r=grid.size();
    int c=grid[0].size();
    int ans=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==1){
                ans++;
                dfs(grid, i, j, r, c);
            }
        }
    }

    return ans;
}

int main(){
    vector<vector<int>>v={
        {0,1},
        {1,0},
        {1,1},
        {1,0}};
    cout<<numIslands(v);
    return 0;
}