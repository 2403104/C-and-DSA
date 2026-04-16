# include <bits/stdc++.h>
class Solution {
public:
    int n, m;
    bool check(int i, int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        n= grid.size();
        m= grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m, vector<int>(m, 0)));
        int dx[3]={-1,0,1};
        for(int a=0;a<m;a++){
            for(int b=0;b<m;b++){
                if(b==a) dp[n-1][a][b]=grid[n-1][a];
                else dp[n-1][a][b]=grid[n-1][a]+grid[n-1][b];
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j_1=0;j_1<m;j_1++){
                for(int j_2=0;j_2<m;j_2++){
                    int maxi=0;
                    for(int k=0;k<3;k++){
                        for(int l=0;l<3;l++){
                            int new_j1=j_1+dx[k];
                            int new_j2=j_2+dx[l];
                            if(check(i+1,new_j1) && check(i+1,new_j2)){
                                int val=0;
                                if(j_1==j_2) val+=grid[i][j_1];
                                else val+=grid[i][j_1]+grid[i][j_2];
                                val+=dp[i+1][new_j1][new_j2];
                                maxi=max(maxi,val);
                            }
                        }
                    }
                    dp[i][j_1][j_2]=maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};
using namespace std;
int main(){

    return 0;
}