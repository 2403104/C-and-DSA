#include <bits/stdc++.h>
using namespace std;
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
//LIS USING BINARY SEARCH
int lis(vector<int>arr){
    vector<int>curr;
    int n=arr.size();
    int ans=0;
    rep(i,0,n){
        if(curr.empty() || arr[i]>curr.back()){
            curr.push_back(arr[i]);
        }else{
            auto it=lower_bound(curr.begin(),curr.end(),arr[i]);
            *it=arr[i];
        }
        ans=max(ans,(int)curr.size());
    }
    return ans;
}
int main()
{
    vi arr = {10, 9, 2, 5, 3, 7, 11, 18};
    cout<<lis(arr);
    // int n = arr.size();
    // vi dp(n, 1);
    // vector<vi> stDp(n);
    // for (int i = 0; i < n; i++)
    //     stDp[i].push_back(arr[i]);
    // rep(i, 1, n)
    // {
    //     rep(j, 0, i)
    //     {
    //         if (arr[i] > arr[j])
    //         {
    //             if (dp[i] < dp[j] + 1)
    //             {
    //                 dp[i] = 1 + dp[j];
    //                 stDp[i] = stDp[j];
    //                 stDp[i].push_back(arr[i]);
    //             }
    //         }
    //     }
    // }
    // int maxi = *max_element(dp.begin(), dp.end());
    // for (int i = 0; i < n; i++)
    // {
    //     if (dp[i] == maxi)
    //     {
    //         for (auto it : stDp[i])
    //             cout << it << " ";
    //         break;
    //     }
    // }

    return 0;
}