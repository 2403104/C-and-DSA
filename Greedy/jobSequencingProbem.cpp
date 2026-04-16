# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;


int main(){
    vector<int>dl={4,1,1,1};
    vector<int>profit={40,10,40,30};
    int n=dl.size();
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        if(mp.find(dl[i])==mp.end()){
            mp[dl[i]]=profit[i];
        }else {
            mp[dl[i]]=max(mp[dl[i]],profit[i]);
        }
    }
    int ans=0;
    for(auto it : mp){
        ans+=it.second;
    }
    cout<<ans;

    return 0;
}