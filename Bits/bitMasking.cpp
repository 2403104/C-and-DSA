#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define pb push_back
#define p push
#define F first
#define S second
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;

void subset(string s, int idx,string curr){
    if(idx==s.length()) {
        cout<<curr<<endl;
        return;
    }
    subset(s,idx+1,curr);
    subset(s,idx+1,curr+s[idx]);
}
/*
remove the last set bit (take the and with n-1 or xor with msb)
*/
int helper(int num){
    int cnt=0;
    while(num){
        cnt+=(num&1);
        num=num>>1;
    }
    return cnt;
}
int cntBits(int a, int b){
    int count=0;
    for(int i=a;i<=b;i++){
        if((i&1)==0 && i<b){
            count+=2*helper(i)+1;
            i++;
            continue;
        }
        count+=helper(i);
    }
    return count;
}
int uniqNum3(vi &arr){//each number appears thrice except one num
    vi count(32,0);
    for(auto num : arr){
        int j=0;
        while(num){
            count[j]+=(num&1);
            j++;
            num=num>>1;
        }
    }
    int ans=0;
    for(int i=0;i<32;i++){
        count[i]%=3;
        ans=ans | (1<<i)*count[i];
    }
    return ans;
}
int main(){
    // string s="ABC";
    // int n=s.length();
    // subset(s,0,"");
    // for(int i=0;i<(1<<n);i++){
    //     for(int j=0;j<3;j++){
    //         if(i&(1<<j)){
    //             cout<<s[j];
    //         }
    //     }
    //     cout<<endl;
    // }
    // int n=8;
    // int ans=n^(n & -n);//remove the last set bit
    // cout<<ans;

    return 0;
}