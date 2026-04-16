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
    vector<int>start={0,3,1,5,5,8};
    vector<int>end={5,4,2,9,7,9};
    vector<pair<int,int>>v;
    int n=start.size();
    for(int i=0;i<n;i++){
        v.push_back(make_pair(start[i],end[i]));
    }
    sort(v.begin(),v.end(),[](pair<int,int>&a, pair<int,int>&b){
        return abs(a.first-a.second)<abs(b.first-b.second);
    });
    sort(v.begin(),v.end(),[](pair<int,int>&a, pair<int,int>&b){
        return a.first<b.first;
    });
    int ans=1;
    for(int i=0;i <n;i++){
        int curr=1;
        int endtime=v[i].second;
        for(int j=i+1;j<n;j++){
            if(v[j].first>endtime){
                curr++;
                endtime=v[j].second;
            }
        }
        ans=max(ans,curr);
    }
    cout<<ans;

    return 0;
}