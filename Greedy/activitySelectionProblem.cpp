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
    int n;cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        int s,e;
        cin>>s>>e;
        v.push_back({s,e});
    }
    sort(v.begin(),v.end(),[&](vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    });
    int take=1;
    int end=v[0][1];
    for(int i=1;i<v.size();i++){
        if(v[i][0]>=end){
            take++;
            end=v[i][1];
        }
    }
    cout<<take<<endl;

    return 0;
}