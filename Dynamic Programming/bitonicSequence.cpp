#include <bits/stdc++.h>
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
typedef std::vector<int> vi;
typedef std::vector<vi> vii;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;

using namespace std;
int bitonicSequence(vector<int>&arr){
    int n=arr.size();
    vi dp1(n+1,1),dp2(n+1,1);
    rep(i,1,n){
        rep(j,0,i){
            if(arr[i]>arr[j]){
                dp1[i]=max(dp1[i],1+dp1[j]);
            }
        }
    }
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j]){
                dp2[i]=max(dp2[i],1+dp2[j]);
            }
        }
    }
    int maxi=0;
    for(int i=0;i<n;i++){
        if(dp1[i]==1 || dp2[i]==1) continue;
        maxi=max(maxi,(int)dp1[i]+dp2[i]-1);
    }
    return maxi;
}
int main(){
    vector<int>arr={10, 20, 30};
    cout<<bitonicSequence(arr);
    return 0;
}