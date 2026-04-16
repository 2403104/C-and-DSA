#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int>arr={2,3,7,5};
    int target=19;
    int n=arr.size();
    int totalSum=0;
    for(auto i : arr) totalSum+=i;
    vector<vector<int>> dp(n, vector<int>(totalSum + 1, 0));    
    int mini=1e9;
    for(int i=0;i<n;i++) dp[i][0]=true;
    dp[0][arr[0]]=true;
    for(int i=1;i<n;i++){
        for(int tar=1;tar<=totalSum;tar++){
            bool notTaken=dp[i-1][tar];
            bool taken=false;
            if(arr[i]<=tar){
                taken=dp[i-1][tar-arr[i]];
            }
            dp[i][tar]=taken || notTaken;
        }
    }
    for(int i=0;i<totalSum;i++){//totalSum/2
        if(dp[n-1][i]){
            int s1=i;
            int s2=totalSum-i;
            mini=min(mini,abs(s1-s2));
        }
    }
    cout<<mini<<endl;

    return 0;
}