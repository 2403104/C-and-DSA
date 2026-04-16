# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
bool sorted(int arr[],int n){
    if (n==1){
        return true;
    }
    bool rest_array=sorted(arr+1, n-1);//pointer will shift to the first element
    return (arr[0]<arr[1]) && rest_array;
}
//print in increasing and decreasing order
int first_occurence(int arr[],int n,int i, int key){
    if (i==n) {
        return -1;
    }
    if (arr[i]==key){
        return i;
    }
    return first_occurence(arr,n, i+1,key);
}
int last_occurence(int arr[],int n,int i, int key){
if (i==n) return -1;
int rest_array=last_occurence(arr, n, i+1,key);
if (rest_array!=-1) return rest_array;
if (arr[i]==key) return i;
return -1;
}
int main(){

// int arr[]={1,7,34,56,78,89};
int arr[]={1,7,34,56,78,34,89};
// cout<<sorted(arr,6);
// cout<<first_occurence(arr,7,0,34)<<endl;
// cout<<last_occurence(arr,7,0,34);
    return 0;
}