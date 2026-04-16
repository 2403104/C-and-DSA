// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;
// int divisible(int n, int a ,  int b){
//     int c1=n/a, c2=n/b, c3=n/(a*b);
//     return c1+c2-c3;
// }
// int main(){

// cout<<divisible(50,2,3);

//     return 0;
// }


# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

int gcd(int a,int b){
    while (b!=0){
    int rem=a%b;
    a=b;
    b=rem;

 
    }
    return a;
}
int main(){
//gcd of (a,b)==gcd(a-b,b);gcd(a,b)==gcd(a%b,b)
cout<<gcd(8,24);

    return 0;
}