#include <bits/stdc++.h>
using namespace std;
double pow(int x, int n){
    int temp=n;
    if(n<0) n*=-1;
    double ans=1;
    while(n>0){
        if(n%2!=0) {
            ans*=x;
            n--;
        }
        else {
            n/=2;
            x*=x;
        }
    }
    return (temp>=0)?ans:1.0/ans;
}
int main(){
    int x,n;
    cin>>x>>n;
    cout<<pow(x,n);
    return 0;
}