#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;

bool threeSum(vector<int>v,int target){
    bool found=false;
    sort(v.begin(),v.end());
    for (int i=0;i<v.size()-2;i++){
        int left=target-v[i];
        int st=i+1,end=v.size();
        while(st<end){
            if (v[st]+v[end]==left){
                found =true;
                return found;
            }
            else if (v[st]+v[end]>left) end--;
            else if (v[st]+v[end]<left) st++;
        }
    }
    return found;
}


int main() {
    vector<int> v={12,3,7,1,6,9};
    cout<<threeSum(v,16);

}
