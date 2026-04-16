#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>ans;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            if(i==n/i){
                ans.push_back(i);
                continue;
            }
            ans.push_back(i);//if i divides n the n/i all divides n so both are divisor
            ans.push_back(n/i);
        }
    }
    // sort(ans.begin(),ans.end());
    for(auto it :ans) cout<<it<<" ";


    return 0;
}