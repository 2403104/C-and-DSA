#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getbit(int n, int pos)
{ // left shift on 1 by position
    // taking and with 1 left shifted by pos
    return (n & (1 << pos)) ==1; // if  it not then it will return true and true is considered as 1
    return (n & (1 << pos)) !=0; // if  it not then it will return true and true is considered as 1
}
int setbit(int n, int pos)
{
    return (n | (1 << pos));
}

int clearbit(int n, int pos)
{
    return (n & (~(1 << pos))); // negation will give only 0 at that point where we have to delete and then we taking intesection to get the desired resutl
}

int updatebit(int n, int pos, int val)
{
    int mask = ~(1 << pos); // clear bit
    n = n & mask;
    return (n | (val << pos));
}

int main()
{
    // int n=8;
    // int i=3;
    // cout<<getbit(n,i)<<endl;
    // cout<<setbit(n,i)<<endl;
    // cout<<clearbit(n,i);
    // cout<<updatebit(10,2,1);
    int n=10;
    int y=~n;
    cout<<y;

    return 0;
}

// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;
// bool ispowertwo(int n){
//     return (n & (n-1))==0;
// }
// int count_one(int n){
//     int count=0;
//     while (n){
//         n=n&(n-1);
//         count+=1;
//     }
//     return count;
// }
// // generate all subset
// void subset(char arr[],int n){//we will check the the bit in the every binary of the number till n if it is 1 then print that element in the arr
//     for (int i=0; i<(1<<n);i++){
//         //(1<<n)==two to the power n viz is equal to the total number of element in the subset
//         for (int j=0;j<n;j++){
//             if (i & (1<<j)){
//                 cout<<arr[j]<<" ";
//             }

//         }
//         cout<<endl;
//     }
// }
// int main(){
// /*
// by flipping all the bits from the rightmost element the we get a number decresed by 1
// binary of 2**n has only one bit 1 set at any place
// n and n-1 has the same bit except the right most bit
// */
// // cout<<ispowertwo(16);
// cout<<count_one(0);
// char arr[3]={'a','b','c'};
// subset(arr,3);
//     return 0;
// }