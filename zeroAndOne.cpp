#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;// n for 0, m for 1
    if(m>2*n+2 || n>m+1){
        cout<<-1<<endl;
        return 0;
    }
    string ans="";
    while(m>0 || n>0){
        if(m>n){
            if(m>1){
                ans+="11";
                m-=2;
            }else{
                ans+="1";
                m--;
            }
            if(n>0) {
                ans+="0";
                n--;
            }
        }
        else{
            ans+="10";
            m--;
            n--;
        }
    }
    cout<<ans<<endl;
    return 0;
}