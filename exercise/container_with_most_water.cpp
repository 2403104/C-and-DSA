# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main(){
// vector<int>height={1,8,6,2,5,4,8,3,7};
// int max_water=0;
// for (int i=0;i<height.size();i++){
//     int water=0;
//     for (int j=i+1;j<height.size();j++){
//         int width=(j-1);
//         int hgt=min(height[i],height[j]);
//         water=width*hgt;
//         if (max_water<water) max_water=water;
//     }
// }
// cout<<max_water;

//OPTICAL SOLUTION(two pointer)
vector<int>arr={1,8,6,2,5,4,8,3,7};
int lp=0, rp=arr.size()-1;
int max_water=0;
while (lp<rp){
    int width=rp-lp;
    int height=min(arr[rp],arr[lp]);
    int water=(height)*width;
    max_water=max(max_water,water);
    arr[lp]<arr[rp] ? lp++: rp--;
}
cout<<max_water;


    return 0;
}