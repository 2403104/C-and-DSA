#include <iostream>
using namespace std;
//PASS BY VALUE
void cout_hello(){
    cout<<"Hello! How are you";
    return ;
}

int sum(int a, int b){
    int sum=a+b;
    return sum;
}

int digit_sum(int a){
    int sum=0;
    while (a!=0){
        sum+=a%10;
        a=a/10;
    }
    return sum;
}

int min(int a,int b){
    int minm=a;
    if (b<a) minm=b;
    return minm;
}
int main(){
// cout_hello();

// int a =45;
// int b=89;
// int ans=sum(a,b);
// cout<<sum(9,5);
// cout<<min(a,b);

//STATIC AND DYNAMIC MEMORY;(current function is always on  the top of the stack)

// int  num=456;
// cout<<digit_sum(num);


    return 0;
}