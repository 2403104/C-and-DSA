# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main(){

int arr[11]={-5,-4,1,5,7,8,9,12,15,17,58};
int target=17;
int st=0;
int end=10;
while(st<end){
    int mid=(st+end)/2;
    if (arr[mid]==target){ 
    cout<<"Found";
    break;}
    else if (target>arr[mid]) st=mid+1;
    else end=mid-1;
}




    return 0;
}