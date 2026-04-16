# include <iostream>
# include <vector>
# include <stack>
using namespace std;
int getMaxArea(vector<int>v){
    int n=v.size(),ans=0,i=0;
    stack<int>s;
    v.push_back(0);
    while(i<n){
        while(!s.empty() && v[s.top()]>v[i]){
            int t=s.top();
            int h=v[t];
            s.pop();
            if (s.empty()){
                ans=max(ans,h*i);
            }
            else{
                ans=max(ans,h*(i-s.top()-1));
            }
        }
        s.push(i);
        i++;
    }
    return ans;
}

int main(){

    vector<int>v={2,1,5,6,2,3};
    cout<<getMaxArea(v);
    return 0;
}