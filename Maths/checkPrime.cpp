#include <bits/stdc++.h>
using namespace std;
bool prime(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){//instead of checking till n check till root n
        if(n%i==0) {
            cnt++;
            if(n/i!=i) cnt++;
        }
        if(cnt>2) break;
    }
    return cnt==2;
}
int main(){
    //if  a number is divisible by 1 and itself and the total number of divisor is 2
    int n;
    cin>>n;
    cout<<prime(n);
    return 0;
}