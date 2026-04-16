# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
bool myCompare(pair<int, int> p1, pair<int,int>p2){
    return p1.first<p2.first;
}
int main(){
vector<int> nums={8,7,5,4,2,1,3};
// nums.push_back(10);
// nums.pop_back();//pop the last element from the nums     
// auto s=5;
// cout<<s;
// int n=nums.back();//take the last element 
// cout<<n;
// for (auto i: nums){//auto self decides the data type of element
// cout<<i<<" ";
// }

// vector<int> v(8,12);//(size , all element value in the vector v)
// for (int i: v){
//     cout<<i<<" ";
// }

// swap(nums,v);//all the element in the num is swapped by the elements of v
// for (int i: nums){//number of elements is equal to the maxm of nums,v
//     cout<<i<<" ";
// }

// pair<int, char > p;//used to store a pair of same or different type
// p.first=57;
// p.second='a';

// cout<<p.first;
// int  arr[]={4,5,1,2,7,8,3,9,6};
// vector<pair<int, int>>v;
//     for (int i=0;i<(sizeof(arr)/sizeof(arr[0]));i++){
//         // pair<int,int>p;
//         // p.first=arr[i];
//         // p.second=i;
//         // v.push_back(p);

//         v.push_back(make_pair(arr[i],i));//short cut 
        
    // }
    // sort(v.begin(),v.end(),myCompare);
    // for (int i=0;i<v.size();i++){
    //     cout<<"("<<v[i].first<<","<<v[i].second<<")"<<" ";
        
    // }

// string s="ankit";
// cout<<s;
    return 0;
}