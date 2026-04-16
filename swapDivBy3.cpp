#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define input(arr) for(auto &it : arr) cin>>it;
#define pb push_back
#define p push
#define F first
#define S second
typedef std::vector<int> vi;
typedef std::vector<long long> vl;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int cnt=0;
    int even1=0,odd1=0;
    int odd0=0,even0=0;
    rep(i,0,n){
        if(s[n-i-1]=='1') {
            if(i%2==0) even1++;
            else odd1++;
        }else{
            if(i%2==0) even0++;
            else odd0++;
        }
    }
    even1%=3;
    odd1%=3;
    int diff=abs(odd1-even1);
    if(diff==0){
        cout<<0<<endl;
        return;
    }
    if((even1==0 && odd1==1) || (odd1==0 && even1==1)) {
        cout<<-1<<endl;
        return;
    }
    if((even1==0 && odd1==2) || (odd1==0 && even1==2)) {
        cout<<1<<endl;
        return;
    }
    if(even1==1 && odd1==1){
        if(odd0>0 || odd1>0) {
            cout<<1<<endl;
            return;
        }else{
            cout<<-1<<endl;
            return;
        }
    }
    if(even1==1 && odd1==2){
        if(odd0>0 ) cout<<1<<endl;
        else if(even0>1) cout<<2<<endl;
        else cout<<0<<endl;
        return;
    }    
    if(even1==2 && odd1==1){
        if(even0>0 ) cout<<1<<endl;
        else if(odd0>1) cout<<2<<endl;
        else cout<<-1<<endl;
        return;
    }

    
    
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr); 
    #endif

    int t;
    cin>>t;
    // t=1;
    while(t--){
        solve();
    }

    return 0;
}