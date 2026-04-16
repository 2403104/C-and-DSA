# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;


int main(){
    vector<vector<int>>v={
        {0,0,0},
        {0,-1,0},
        {0,0,0}
        };

    // vector<vector<int>>v={{0,0},{0,-1}};
    int r=v.size();
    int c=v[0].size();
    vector<vector<int>>dp(r,vector<int>(c,0));
    for (int i = 0; i < r; i++) {
        if (v[i][0] == -1) break;  
        dp[i][0] = 1;
    }
    for (int j = 0; j < c; j++) {
        if (v[0][j] == -1) break;  
        dp[0][j] = 1;
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){
            if(v[i][j]==-1) {
                dp[i][j]=0;;
            }else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout<<dp[r-1][c-1];
    return 0;
}