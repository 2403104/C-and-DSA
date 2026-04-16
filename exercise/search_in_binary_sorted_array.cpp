# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int search(vector<int>nums,int target){
    int st=0,end=nums.size();
    while (st<end){
        int mid=(st+end)/2;
        if (nums[mid]==target) return mid;
        if (nums[st]<nums[mid]){
            if (nums[st]<=target<=nums[end]){
                end=mid-1;
            }
            else{
                st=mid+1;
            }
        }
        else{
            if(nums[mid]<=target<=nums[end]){
                st=mid+1;
            }
            else{
                end=mid-1;
            }
        }
    }
    return -1;
}
int main(){

//either left half or right half is sorted
vector<int>lst={3,4,5,6,7,8,9,0,1,2};
int target=1;

cout<<search(lst,target);
    return 0;
}