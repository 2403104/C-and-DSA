#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=15;
    int b=-2;
    string ans="";
    while(n!=0){
        int rem=n%(b);
        if(rem<0){
            rem+=abs(b);
            n=(n-rem)/(b);
        }else{
            n/=b;
        }
        ans=to_string(rem)+ans;
    }    
    cout<<ans;
    return 0;
}