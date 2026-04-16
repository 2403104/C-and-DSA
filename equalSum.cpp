#include <bits/stdc++.h>
using namespace std;
bool solve(vector<int>&nums,int idx, vector<vector<int>>&ans,int target){
    int s=ans.size();
    if(idx==nums.size()){
        vector<int>v=ans[0];
        int side=accumulate(v.begin(),v.end(),0);
        for(int i=1;i<s;i++){
            vector<int>currV=ans[i];
            int currSum=accumulate(currV.begin(),currV.end(),0);
            if(side!=currSum) return false;
        }
        return true;
    }
    for(int i=0;i<s;i++){
        vector<int>v=ans[i];
        int crrSum=accumulate(v.begin(),v.end(),0);
        if(crrSum+nums[idx]>target) continue;
        ans[i].push_back(nums[idx]);
        if(solve(nums,idx+1,ans,target)) return true;
        ans[i].pop_back();
        if(ans[i].empty())  break;
    }
    return false;
}
//split into 4
int main(){
    vector<int> nums = {1, 1, 1, 1, 4, 4, 4, 4};
    int sum = accumulate(nums.begin(), nums.end(), 0);
    
    if (sum % 4 != 0) {
        cout << "Not possible to form 4 equal subsets.\n";
        return 0;
    }
  
    int target = sum / 4;
    vector<vector<int>> ans(4);  
    if (solve(nums, 0, ans, target)) {
        cout << "Possible partitions:\n";
        for (auto& v : ans) {
            for (int num : v) cout << num << " ";
            cout << endl;
        }
    } else {
        cout << "Not possible to form a square.\n";
    }

    return 0;
}