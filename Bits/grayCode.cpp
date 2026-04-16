#include <bits/stdc++.h>
using namespace std;
vector<int> grayCode(int n){
    int total=1<<n;
    vector<int>ans;
    for(int i=0;i<total;i++){
        ans.push_back(i^(i>>1));
    }
    return ans;
}
int main(){

    return 0;
}