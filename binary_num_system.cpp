#include <iostream>
using namespace std;

void decimal_binary(int n){
    int ans=0;
    int pow=1;
    while (n!=0){
        int rem=n%2;
        n=n/2;
        ans+=rem*pow;
        pow*=10;
    }
    cout<<ans;
    // if (n==0) return;
    // decimal_binary(n/2);
    // cout<<n%2;
    return ;
}

void binary_decimal(int n){
    int ans=0;
    int two=1;
    while (n>0){
        int rem=n%10;
        n=n/10;
        ans+=two*rem;
        two*=2;
    }
    cout<<ans;
    return ;
}


int main(){

// int n=10;
// decimal_binary(n);

// int bin=101;
// binary_decimal(bin);



    return 0;
}