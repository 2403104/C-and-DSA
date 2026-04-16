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
    vector<vector<int>>v={{5,9,6},{1,5,2}};
    int r=v.size();
    int c=v[0].size();
    vector<vector<int>>dp=v;
    for(int j=1;j<c;j++){
        dp[0][j]+=dp[0][j-1];
    }
    for(int i=1;i<r;i++){
        dp[i][0]+=dp[i-1][0];
    }
    for(int i=1;i<r;i++){
        for(int j=1;j<c;j++){

                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+v[i][j];
            
        }
    }

    cout<<dp[r-1][c-1];
    return 0;
}