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

    vector<int> v;
    map<int,int> cnt;
    int prefSum=0;
    rep(i,0,v.size()){
        prefSum+=v[i];
        cnt[prefSum]++;
    }
    int ans=0;
    map<int,int> :: iterator it;
    for (it=cnt.begin();it!=cnt.end();it++){
        int c=it->second;
        ans+=(c*(c-1))/2;
        if (it->first==0){
            ans+=it->second;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}