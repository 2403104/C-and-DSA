#include <bits/stdc++.h>
using namespace std;
int targetSum(vector<int>&arr , int target, int idx){
    if(idx==0){
        if(target==arr[0] || target==-arr[0]) return 1;
        return 0;
    }
    int ans=0;
    ans+=targetSum(arr, target+arr[idx],idx-1);
    ans+=targetSum(arr, target-arr[idx],idx-1);

    return ans;
}
int main(){
    vector<int>arr={1,2,3,1};
    int target=3;
    int n=arr.size();
    cout<<targetSum(arr, target, n-1);

    //this question is similar to the difference between the two partition equal to the target
    
    return 0;
}