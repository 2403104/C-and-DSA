#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int>&price){
    int n=price.size();
    if(n==0) return 0;
    vector<int>dp(n,0);
    dp[0]=price[0];
    int minPrice=price[0];
    dp[1]=price[1]-minPrice;
    minPrice=min(minPrice,price[1]);
    for(int i=2;i<n;i++){
        dp[i]=max(dp[i-1],price[i]-minPrice);
        minPrice=min(minPrice,price[i]);
    }
    return (dp.back()>0)?dp.back():0;
}
int main(){
    vector<int>price={7,1,5,3,6,4};
    cout<<maxProfit(price);
    return 0;
}