# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;
int climb(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    if(n==3) return 3;
    return climb(n-1)+climb(n-2);
}

int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n]<<endl;
    cout<<climb(n);
    return 0;
}