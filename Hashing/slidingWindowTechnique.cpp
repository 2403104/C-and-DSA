# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;

#define vi vector<int>;
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define ff first
#define ss second



int main(){
    vector<int> v={-2,10,1,3,2,-1,4,5};
    int k=3;
    int s=0, ans=INT16_MAX;
    rep(i,0,k){
        s+=v[i];
    }
    ans=min(ans,s);
    rep(i,1,v.size()+1-k){
        s-=v[i-1];
        s+=v[i+k-1];
        ans=min(ans,s);
    }
    cout<<ans<<endl;

    return 0;
}