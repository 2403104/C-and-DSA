//SIEVE OF ERATOSTHENES
# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
void prime_sieve(int n){
    int prime[n]={0};
    for (int i=2;i<n;i++){
        if (prime[i]==0){
            for (int j=i*i;j<n;j++){//start from the square of that
                if (j%i==0)
          {      prime[j]=1;}
            }
        }
    }
    for (int j=2;j<n;j++){
        if (prime[j]!=1){
        cout<<j<<" ";}
    }
}
int main(){
prime_sieve(50);


    return 0;
}



// # include <iostream>
// # include <vector>
// # include <algorithm>
// using namespace std;
// void primefactor(int n){
//     int spf[100]={0};
//     for (int i=2;i<100;i++){
        
//             spf[i]=i;
//     }
//     for (int i=2;i<=n;i++){
//         if( spf[i]==i){
//             for (int j=i*i;j<=n;j+=i){
//                 if (spf[j]==j) spf[j]=i;
//             }
//         }
//     }
//     while (n!=1){
//         cout<<spf[n]<<" ";

//         n=n/spf[n];
//     }
//     return ;
//     }
    

// int main(){

// primefactor(45);

//     return 0;
// }