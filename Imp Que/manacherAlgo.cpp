#include <bits/stdc++.h>
using namespace std;
vector<int> longestPalindrome(string s){
    int n=s.size();
    if(n==0) return {};
    string t="@";
    for(char ch : s){
        t+="#"+s.substr(1,ch);
    }
    t+='$';
    int m=t.size();
    vector<int>radius(m,0);//radius of palindrome centered at i
    int center=0,right=0;
    for(int i=1;i<m-1;i++){
        int mirror=2*center-i;
        if(i<right){
            radius[i]=min(right-i,radius[mirror]);
        }
        if(t[i+radius[i]+1]==t[i-radius[i]-1]){
            radius[i]++;
        }
        if(i+radius[i]>right){
            center=i;
            right=i+radius[i];
        }
    }
    vector<int>ans(n);
    for(int i=0;i<n;i++){
        ans[i]=radius[i*2+2];
    }
    return ans;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("output.txt", "w", stderr); 
    #endif

    

    return 0;
}