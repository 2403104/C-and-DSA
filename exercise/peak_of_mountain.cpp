# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int mountainPeak(vector<int>nums){
    int st=0,end=nums.size()-1;
    while(st<end){
        int mid=(st+end)/2;
        if (nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
            return mid;
        }
        else if (nums[mid-1]<nums[mid] && nums[mid]<nums[mid+1]) st=mid+1;
        else if (nums[mid-1]>nums[mid] && nums[mid]>nums[mid+1]) end=mid-1;

    }
}
int main(){
vector<int>nums={1,2,3,4,5,6,7,2,1,0};
cout<<nums[mountainPeak(nums)];


    return 0;
}