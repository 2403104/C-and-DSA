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
    int n;
    cin>>n;

    vector<int> v(n);
    rep(i,0,n)
        cin>>v[i];
    
    int x;
    cin>>x;

    sort(v.begin(),v.end(),greater<int>());
    int ans=0;
    
    for (int i=0;i<n;i++){
        ans+=x/v[i];
        x-=(x/v[i])*v[i];
    }

    cout<<ans<<endl;




    return 0;
}