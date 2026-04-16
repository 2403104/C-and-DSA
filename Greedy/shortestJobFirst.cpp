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
    vector<int>v={4,3,7,1,2};
    sort(v.begin(),v.end());
    int ans=0;
    int curr=0;
    //1 2 3 4 7
    for(int t : v){
        cout<<curr<<" ";
        ans+=curr;
        curr+=t;
    }
    cout<<ans/v.size();



    return 0;
}