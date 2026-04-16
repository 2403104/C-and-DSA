#include <bits/stdc++.h>
using namespace std;
bool prime(int n){
    int cnt=0;
    for(int i=1;i*i<=n;i++){
        if(n%i==0){
            cnt++;
            if(n/i!=i) cnt++;
        }
        if(cnt>2) return false;
    }
    return cnt==2;
}
vector<int>primeFactor1(int n){
    vector<int>ans;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            if(prime(i)) ans.push_back(i);
            if(n/i!=i){
                if(prime(n/i)) ans.push_back(n/i);
            }
        }
    }
    return ans;
}
//for large number n , primeFactorial2 is still runs in O(n) like 37
vector<int>primeFactor2(int n){
    vector<int>ans;
    int temp=n;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            ans.push_back(i);
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n!=1) ans.push_back(n);
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int>ans=primeFactor2(n);
    for(auto it : ans) cout<<it<<" ";
    return 0;
}