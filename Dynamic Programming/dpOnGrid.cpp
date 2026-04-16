# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;

int countPath(int i, int j, int r, int c){
    if(i<0 || i>=r || j<0 || j>=c ) return 0;
    if( i==r-1 && j==c-1) return 1;
    int right=countPath(i+1,j,r,c);
    int left=countPath(i,j+1,r,c);
    return left+right;
}

int main(){
    int n,m;
    cin>>n>>m;
    // vector<vector<int>>dp(n,vector<int>(m,0));
    // for(int i=0;i<n;i++){
    //     for(int j =0;j<m;j++){
    //         if(i==0 ){
    //             dp[0][j]=1;
    //         }
    //         else if(j==0){
    //             dp[i][0]=1;
    //         }
    //         else{
    //             dp[i][j]=dp[i-1][j]+dp[i][j-1];
    //         }
    //     }
    // }
    // cout<<countPath(0,0,n,m)<<endl;
    // cout<<dp[n-1][m-1]<<endl;
    
    //SPACE OPTIMISED
    vector<int>dp(m,1);
    for(int i=0;i<n-1;i++){
        vector<int>curr(m,0);
        curr[0]=1;
        for(int i=1;i<m;i++){
            curr[i]=curr[i-1]+dp[i];
        }
        dp=curr;
    }

    cout<<dp.back();

    return 0;
}