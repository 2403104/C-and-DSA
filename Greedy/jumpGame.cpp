# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;

bool checkPath(vector<int>&arr){
    int maxIdx=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(i>maxIdx) return false;
        maxIdx=max(maxIdx,i+arr[i]);
    }
    return true;
}

int main(){
    
    vector<int>arr={2,3,1,0,4};
    cout<<checkPath(arr);

    return 0;
}