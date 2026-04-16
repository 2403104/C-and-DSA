#include <iostream>
using namespace std;

//pass by reference(passing the address)
void change_arr(int arr[],int size){
    for (int i=0;i<size;i++){
        arr[i]=arr[i]*5;
    }
    return ;
}
int main(){
    //data structures(used to store data)
    int marks[5]={8,2,5,3,9};//size can of any  length
    int size=5;
    // int sml=marks[0];
    // for (int i=0;i<5;i++){
        // if (marks[i]<sml){
        //     sml=marks[i];
        // }
    //     sml=min(sml,marks[i]);
    // }
    // cout<<sml;

int arr[]={8,7,4,9,5,7,4,9,6};
// change_arr(arr,5);
// for (int i=0;i<5;i++){
// cout<<arr[i]<<endl;
// }

int count=9;
for (int i=0,j=8;i<=j;i++,j--){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

for (int i=0;i<9;i++){
    cout<<arr[i]<<" ";
}

    return 0;
}