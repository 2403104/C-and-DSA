#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, a, b) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
typedef std::vector<int> vi;
typedef std::vector<vi> vii;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;

using namespace std;
int buyAndSell(vi &price,int idx, bool canBuy,vii &dp){
    if(dp[idx][canBuy]!=-1) return dp[idx][canBuy];
    if(idx==price.size()) return 0;
    int profit=0;
    if(canBuy){
        profit+=max(-price[idx]+buyAndSell(price,idx+1,false,dp),buyAndSell(price,idx+1,true,dp));
    }
    else{
        profit+=max(price[idx]+buyAndSell(price,idx+1,true,dp),buyAndSell(price,idx+1,false,dp));
    }
    return dp[idx][canBuy] = profit;
}
int main(){

    vi price={1,4,5,2,6,8,9,3,5,4,7};
    int n=price.size();
    // vii dp(n+1,vi(2,-1));
    // int  ans=buyAndSell(arr,0,true,dp);
    
    vii dp(n+1,vi(2,0));
    dp[n][0] = dp[n][1] = 0;
    for(int idx=n-1;idx>=0;idx--){
        for(int  canBuy=0;canBuy<2;canBuy++){
            int profit=0;
            if(canBuy){
                profit+=max(-price[idx]+dp[idx+1][false],dp[idx+1][true]);
            }
            else{
                profit+=max(price[idx]+dp[idx+1][true],dp[idx+1][false]);
            }
            dp[idx][canBuy]=profit;
        }
    }
    return 0;
}