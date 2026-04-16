# include <iostream>
# include <algorithm>
# include <vector>
# include <cmath>
# include <string>
using namespace std;
int main(){
// vector<int> slice(nums.begin() + start, nums.begin() + end);
// double x=56;
// // double ans;
// float ans;
// ans =sqrt(x);//cmath
// cout<<ans;

// int base=4;
// int power=2;
// int ans=pow(base, power);//cmath
// cout<<ans;

// int arr[10]={5,1,4,7,8,9,6,2,5,3};
// sort(arr,arr+sizeof(arr)/sizeof(arr[0]));//sort for int array
// for (int i=0;i<10;i++){
//     cout<<arr[i]<<" ";
// }

// int ans=sizeof(arr);//give the size of the array not the length of the array;
// int ans=sizeof(arr)/sizeof(arr[0]);//gives the length of the array
// cout<<ans;

vector<int> arr={1,5,4,9,2,6,7,2,8};
// cout<<arr.size();//use only for vectors
// sort(arr.begin(),arr.end());//sort for vectors
// for (int i: arr){
//     cout<<i<<" ";
// }

// auto index=find(arr.begin(),arr.end(),5);
// if (index!=arr.end()){
//     cout<<index-arr.begin();
// }
// cout<<*index;//it will give the value at that index

//  The auto keyword is a simple way to declare a variable that has a complicated type.

string s="ANKIT";
// string s="ankit";
// char ans=tolower(s[0]);
// cout<<ans;

// for (auto & i:s){
//     i=tolower(i);//convert to lower case
//     // i=toupper(i);//convert to upper case
// }
// cout<<tolower(s)//cant use
// string ans="";
// for (auto i : s){
//     ans+=tolower(i);
// };
// cout<<ans;

//STRING TO INTEGER
// string str="4578";
// int num=stoi(str);
// cout<<num;

//INTEGER TO STRING
// int num=4578;
// string str=to_string(num);
// cout<<str;

//CHAR TO INT
// char ch='5';
// int nums=ch-'0';
// cout<<nums;


//INT TO CHAR
// int n = 4;
// char ch= n +'0';
// cout<<ch;

//GET ASCII
// char n='a';
// int num=(int)n;
// cout<<num;

//GET DIGIT FROM ASCII
// int n=98;
// char ans=(char)n;
// cout<<ans;
         
// vector<vector<int>>ans={{1,2,3},{4,5,6},{7,8,9}};
// vector<int>curr=ans.back();//will give the last array in the vector vector <int>>
// for (int i: curr){
//     cout<<i<<" ";
// }

//isalnum(check if char is  digit or alpha)

// vector<int>v1;
// vector<int>v2;
// v1.insert(v1.end(),v2.begin(),v2.end());

//int sum=accumulate(v.begin(),v.end(),0);
// vector<int> v = {1, 3, 3, 5, 7};
// auto lb = lower_bound(v.begin(), v.end(), 3); //returns an iterator pointing to first element grater than or equal to 3
// cout << *lb; // Output: 3 (first occurrence of 3)

// vector<int> v1 = {1, 3, 3, 5, 7};
// auto ub = upper_bound(v1.begin(), v1.end(), 3); //returns an iterator pointing to the first element grater than 3
// cout << *ub; // Output: 5 (first element greater than 3)

// transform( start of input, end of input, start of output, function to apply);
// string str = "Hello, WORLD!";
    
// transform(str.begin(), str.end(), str.begin(), ::tolower);
// cout<<str;
// while(includes(sa.begin(), sa.end(), sb.begin(), sb.end()))//check the subset of the set

    return 0;
}