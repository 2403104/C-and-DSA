# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;
int minPathSum(vector<vector<int>>&v,int i,int j,int r){
    if(i==r-1) return v[i][j];
    int right=v[i][j]+minPathSum(v,i+1,j,r);
    int dig=v[i][j]+minPathSum(v,i+1,j+1,r);
    return min({right,dig});
}

int main(){
    vector<vector<int>>v={
        {1},
        {2,3},
        {4,9,6},
        {5,4,2,3}};
    
        // int n=v.back().size();
        // vector<vector<int>>dp(n,vector<int>(n,0));
        // for(int i=0;i<n;i++){
        //     dp[n-1][i]=v[n-1][i];
        // }
        // for(int i=n-2;i>=0;i--){
        //     for(int j=i;j>=0;j--){
        //         dp[i][j]=v[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
        //     }
        // }

        //SPACE OPTIMISATION
        //There is a need of only last row 

    // cout<<minPathSum(v,0,0,v.size())<<endl;
    // cout<<dp[0][0];

    return 0;
}