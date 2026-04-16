#include <bits/stdc++.h>
using namespace std;
void bubbleSort(vector<int>&v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        bool needed=false;
        for(int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1]) {
                swap(v[j],v[j+1]);
                needed=true;
            }
        }
        for(int i=0;i<n;i++) cout<<v[i]<<" ";
        cout<<endl;
        if(!needed) break;
    }
}
void reverseBubbleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (nums[j] < nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
            }
        }
        for(int i=0;i<n;i++) cout<<nums[i]<<" ";
        cout<<endl;
    }
}

void selectionSort(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        int mini=arr[i];
        int k=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<mini){
                mini=arr[j];
                k=j;
            }
        }
        if(mini!=arr[i]){
            swap(arr[i],arr[k]);
        }
    }
}

void insertionSort(vector<int>&arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
        cout<<endl;
    }
}

void reverseInsertionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        int key = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] < key) {
            nums[j + 1] = nums[j];
            --j;
        }
        nums[j + 1] = key;
        cout<<endl;
    }
}
void countSort(vector<int>&arr){
    int maxi=*max_element(arr.begin(),arr.end());
    int n=arr.size();
    vector<int>cnt(maxi+1,0),ans(n);
    for(auto it : arr) cnt[it]++;
    for(int i=1;i<=maxi;i++) cnt[i]+=cnt[i-1];
    for(int i=0;i<n;i++){
        cnt[arr[i]]--;
        ans[cnt[arr[i]]]=arr[i];
    }
    arr=ans;
}
int partition(vector<int>&arr, int low, int high){
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<=high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[high]);
    return i;
}

void quickSort(vector<int>&arr, int low ,int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
vector<int>arr,aux;
void QUICK_SORT(int low, int high){
    if(low>=high) return ;
    int mid=low+(high-low)/2;
    int left=low,right=high;
    int pivot=aux[mid];
    for(int i=low;i<=high;i++){
        if(i==mid) continue;
        if(aux[i]<=pivot) arr[left++]=aux[i];
        else arr[right--]=aux[i];
    }
    arr[left]=pivot;
    aux=arr;
    QUICK_SORT(low,left-1);
    QUICK_SORT(left+1,high);
}
int invCnt;
void merge(vector<int> &arr, int l, int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    vector<int> L(n1),R(n2);
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int i=0;i<n2;i++) R[i]=arr[m+i+1];
    int i=0,j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) {
            arr[k++]=L[i++];
        }
        else {
            invCnt+=(n1-i);
            arr[k++]=R[j++];
        }
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}
void mergeSort(vector<int>& arr, int l, int r){
    if(l>=r) return; // 1
    int mid=(l+r)/2; // 2
    mergeSort(arr,l,mid); // 3
    mergeSort(arr,mid+1,r); // 4
    merge(arr,l,mid,r); //5
}
int main(){
    vector<int>v={10,5,8,3,4,2,9,1,6,7};
    quickSort(v,0,(int)v.size()-1);
    for(auto it : v) cout<<it<<' ';
    
    return 0;
}