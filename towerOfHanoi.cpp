#include <bits/stdc++.h>
using namespace std;
void towerOfHanoi(int n, char src, char aux , char dest){
    if(n==1){
        cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<endl;
        return;
    }
    towerOfHanoi(n-1,src,dest,aux);//move n-1 from src to aux via dest
    cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1,aux,src,dest);//move n-1 from aux to dest via src

}
int cnt(int n, char src, char aux, char dest){
    if(n==1) return 1;
    return 1+cnt(n-1,src,dest,aux)+cnt(n-1,aux,src,dest);
}
int main(){
    int n;
    cin>>n;
    // towerOfHanoi(n,'A','B','C');
    cout<<cnt(n,'A','B','C');
    return 0;
}