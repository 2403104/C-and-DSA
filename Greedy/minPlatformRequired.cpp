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
    vector<int>arr={900,940,950,1100,1500,1800};
    vector<int>dep={910,1200,1120,1130,1900,2000};

    vector<pair<int,char>>v;
    int n=arr.size();
    for(int i=0;i<n;i++){
        v.push_back({arr[i],'A'});
        v.push_back({dep[i],'D'});
    }
    sort(v.begin(),v.end(),[](pair<int,char>&a, pair<int,char>&b){
        return a.first<b.first;
    });
    int ans=0;
    int curr=0;
    for(int i=0;i<n*2;i++){
        ans=max(ans,curr);
        if(v[i].second=='A'){
            curr++;
        }else{
            curr--;
        }
    }
    ans=max(ans,curr);
    cout<<ans;
    

    return 0;
}