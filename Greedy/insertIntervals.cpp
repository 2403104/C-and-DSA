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
    vector<vector<int>>v={{1,3},{6,9}};
    vector<int>nI={2,5};
    vector<vector<int>>ans;
    v.push_back(nI);
    int n=v.size();
    sort(v.begin(),v.end(),[](vector<int>&a, vector<int>&b){
        return a[0]<b[0];
    });
    vector<int> end=v[0];
    for(int i=1;i<n;i++){
        if(v[i][0]<=end.back()){
            end.back()=max(end.back(),v[i][1]);
        }else{
            ans.push_back(end);
            end=v[i];
        }
    }
    ans.push_back(end);
    
    
    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
    return 0;
}