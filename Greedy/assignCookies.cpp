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
    vector<int>greed={1,5,3,3,4};//allot to this lst
    vector<int>s={4,2,1,2,1,3};
    sort(greed.begin(),greed.end());
    sort(s.begin(),s.end());
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(ans<greed.size() &&  greed[ans]<=s[i]){
            ans++;
        }
    }
    cout<<ans;

    return 0;
}
