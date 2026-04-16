# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

// vector<int> pair_sum(vector<int> nums, int target){
//     vector<int>ans;
//     int n=nums.size();
//     for (int i=0;i<n;i++){
//         for (int j=i+1;j<n;j++){
//             if (nums[i]+nums[j]==target){
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 return ans;
//             }
//         }
//     }
//     return ans;
// }

// vector<int> pair_sum(vector<int> nums, int target){
//     int n=nums.size();
//     vector<int>ans;
//     int st=0;
//     int end=n-1;
//     while(st<end){
//         if (nums[st]+nums[end]==target){
//             ans.push_back(st);
//             ans.push_back(end);
//             return ans;
//         }
//         else if  (nums[st]+nums[end]<target){
//             st+=1;
//         }
//         else if  (nums[st]+nums[end]>target){
//             end-=1;
//         }       
//     }
//     return ans;
// }


// double mypow(double x,int n){
//     if (n==0); return 1.0;
//     if (x==0); return 0.0;
//     if (x==1); return 1.0;
//     if (x==-1 && n%2==0) return 1.0;
//     if (x==-1 && n%2!=0) return -1.0;
//     long biform=n;
//     if (n<0){
//         x=1/x;
//         biform=-biform;
//     }
//     double ans=1;
//     while (biform>0){
//         if (biform%2==1){
//             ans*=x;
//         }
//         x=x*x;
//         cout<<biform;
//         biform/=2;
//     }

//     return ans ;
// }

int main(){
    
    int arr[]={5,-9,6,-9,2,-1,0,8,-8};
    int max_sum=INT16_MIN;
    for (int st=0;st<9;st++){
        int currsum=0;
        for (int end=st;end<9;end++){
            currsum+=arr[end];
            if (currsum>max_sum) max_sum=currsum;
        }
    }
    cout<<max_sum;

//KEDANE'S ALGORITHM    
    // int max_sum=INT16_MIN;
    // int arr[]={-5,-9,-6,-8,-9,-2,-1,-3,-8};
    // int curr_sum=0;
    // for (int i=0;i<9;i++){
    //     curr_sum+=arr[i];
    //     max_sum=max(max_sum,curr_sum);
    //     if (curr_sum<0) curr_sum=0;
    // }
    // cout<<max_sum;

//PAIR SUM
// vector<int>nums={1,7,11,89};;
// int target=100;
// vector<int>ans= pair_sum(nums,target);
// for (int i:ans){
//     cout<<i<<" ";
// }

//MAJORITY ELEMENT
// vector<int>nums={1,1,4,1,5,3,1,4,1,2,1,4,1};
// sort(nums.begin(),nums.end());
// for (int i:nums){
//     cout<<i<<" ";
// }
// int freq=1, curr=nums[0];
// for (int i=1;i<nums.size();i++){
//     if (nums[i-1]==nums[i]) freq++;
//     else{
//         freq=0;
//         curr=nums[i];
//     }
//     if (freq>nums.size()/2) {
//         cout<<curr;
//     break;}
// }

//MOORES ALGORITHM
//  int freq=0,ans=0;
//  vector<int>nums={1,1,4,1,5,3,1,4,1,2,1,4,1};
//  int n=nums.size();
//  for (int i=0;i<n;i++){
//     if (freq==0 ) ans=nums[i];
//     if (nums[i]==ans) freq++;
//     else freq--;
//  }
//  cout<<ans;

// double x=10;
// int n=10;
// double ans=mypow(x,n);
// cout<<ans;

//STOCK BUY AND SELL
// vector<int>arr={7,1,5,3,6,4};
// int max_profit=0;
// int best_buy=arr[0];

// for (int i=1;i<5;i++){
//     for (int j=0;j<i-1;j++){
//         if (arr[i]>arr[j]){
//             int profit=arr[i]-arr[j];
//             if (profit>max_profit) max_profit=profit;
//         }
//     }
//     best_buy=arr[i];
// }

// for (int i=1;i<arr.size();i++){
//     if (arr[i]>best_buy){
//         max_profit=max(max_profit,arr[i]-best_buy);
//     }
//     best_buy=min(best_buy,arr[i]);
// }
// cout<<max_profit;

// string a="ankitkumar";
// string b="ankit";
// vector<int>ans;
// char s='3';
// int ans=s;



    return 0;
}