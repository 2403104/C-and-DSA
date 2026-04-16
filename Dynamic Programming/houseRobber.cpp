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
    vector<int>v={11,9,3,2};
    int n=v.size();
    vector<int>dp(n,-1);
    dp[0]=v[0];
    dp[1]=max(v[0],v[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],v[i]+dp[i-2]);
    }
    cout<<dp[n-1];

    return 0;
}