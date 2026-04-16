// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;
// bool binary_search(vector<vector<int>>nums ,int target){
//     vector<int>ans;
//     int st=0, end=nums.size()-1;
//     while (st<end ){
//                 int mid=st+(st+end)/2;

//         if (nums[mid][0]<=target<=nums[mid][nums[0].size()-1]){
//             int st_=0, end_=nums[0].size()-1;
//             while (st_<end_){
//                 int mid_=st_+(st_+end_)/2;
//                 if (target==nums[mid][mid_]){
//                     // ans.push_back(mid);
//                     // ans.push_back(mid_);
//                     return true;
//                 }
//                 else if (target<nums[mid][mid_]){
//                     end_=mid_-1;
//                 }
//                 else if (target>nums[mid][mid_]){
//                     st_=mid_+1;
//                 }
//             }
//         }
//          else if (target<nums[mid][0]){
//             end=mid-1;
//         }   
//         else if (target> nums[mid][nums[0].size()-1]){
//             st=mid+1;
//         }
        
//     }
//     return false;
// }
// int main(){

// vector<vector<int>> mat={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
// int target=20;
// cout<<binary_search(mat,target);


//     return 0;
// }



//INCREASING ROW WISE AND COLUMN WISE
// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;
// bool binary(vector<vector<int>> mat, int target){
// int row=mat.size(),col=mat[0].size();
// int r=0, c=col-1;
// while(r<row && c>=0){
//     if (target==mat[r][c]) return true;
//     else if (target>mat[r][c]) r++;
//     else c--;
// }
// return false;
// }
// int main(){

// vector<vector<int>>mat={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,36}};
// int target=144;
// cout<<binary(mat,target);
//     return 0;
// }