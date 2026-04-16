# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int search(vector<int>nums){
    int st=0,end=nums.size()-1;
    while (st<end){
        int mid=(st+end)/2;
        if (nums[mid-1]!=nums[mid]!=nums[mid+1])
        return nums[mid];
        else if ((end-mid)%2==0 && nums[mid]==nums[mid+1]){
            st=mid+1;
        }
        else if ((mid-st)%2!=0 && nums[mid-1]==nums[mid]){
            end=mid-1;
        }
    }
    return -1;
}
int main(){
vector<int>nums={1,1,2,2,3,4,4,5,5,6,6,7,7};
cout<<search(nums);


    return 0;
}