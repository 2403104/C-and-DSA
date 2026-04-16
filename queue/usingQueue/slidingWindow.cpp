# include <iostream>
# include <deque>
# include <vector>
using namespace std;
int maxInDeque(deque<int> v){
    int maxm=v[0];
    for (auto i: v){
        maxm=max(maxm, i);
    }
    return maxm;
}
int main(){
vector<int> v={1,3,-1,-3,5,3,6,7};
vector<int> ans;
deque<int>d;
    d.push_back(v[0]);
    d.push_back(v[1]);
    for (int i=2;i<v.size();i++){
        d.push_back(v[i]);
        ans.push_back(maxInDeque(d));
        d.pop_front();
    }
for (auto i: ans){
    cout<<i<<" ";
}
    return 0;
}
