#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
      int n;
      int solve(vector<int>&arr,int target,int idx,vector<vector<int>>&dp){
          if(dp[idx][target]!=-1) return dp[idx][target];
          if(idx==0){
              if(target==0 && arr[0]==0) return 2;
              if (target == 0 || target == arr[0]) return 1;
              return 0;
          }
          int take=0,notTake=0;
          notTake=solve(arr,target,idx-1,dp);
          if(arr[idx]<=target) take=solve(arr,target-arr[idx],idx-1,dp);
          return dp[idx][target] = take+notTake;
      }
      int perfectSum(vector<int>& arr, int target) {
          n = arr.size();
          vector<vector<int>>dp(n,vector<int>(target+1,0));
          for (int i = 0; i < n; i++) dp[i][0] = 1;
          dp[0][0]=(arr[0]==0)?2:1;
          if (arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;
          for (int i = 1; i < n; i++) {
              for (int j = 0; j <= target; j++) {
                  int take = 0, notTake = dp[i - 1][j];
                  if (j >= arr[i]) take = dp[i - 1][j - arr[i]];
                  dp[i][j] = take + notTake;
              }
          }
          // n=arr.size();
          // return solve(arr,target,n-1,dp);
          return dp[n-1][target];
          
      }
  };
bool helper(vector<int>&arr, int target, int idx){
    if(target==0) return true;
    if(idx==0) return target==arr[0];
    bool notTake=helper(arr, target, idx-1);
    bool take=false;
    if(arr[idx]<=target){
        take=helper(arr,target-arr[idx],idx-1);
    }
    return take || notTake;
}
bool partitionEqualSubsetSum(vector<int>&arr){
    int sum=0;
    for(auto i  : arr) sum+=i;
    if(sum%2!=0) return false;
    int half=sum/2;
    return helper(arr, half,arr.size()-1);
}

int main(){
    vector<int>arr={1,2,8,9};
    cout<<partitionEqualSubsetSum(arr);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define p push
#define F first
#define S second
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
void solve(){
    int n,k;
    cin>>n>>k;
    vi A(n),B(n);
    bool notAllNeg=false;
    rep(i,0,n) cin>>A[i];
    rep(i,0,n) {
        cin>>B[i];
        if(B[i]!=-1) notAllNeg=false;
    }
    if(!notAllNeg){
        int prev=-1;
        rep(i,0,n){
            if(B[i]!=-1){
                int curr=A[i]+B[i];
                if(prev==-1) prev=curr;
                if(curr!=prev) {
                    cout<<0<<endl;
                    return;
                }
            }
        }
        int sum;
        rep(i,0,n){
            if(B[i]!=-1){
                sum=A[i]+B[i];
                break;
            }
        }
        cout<<1<<endl;
        return;
    }
    int cnt=k-*max_element(all(A))+1;
    cout<<cnt<<endl;

}
int main(){


    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}