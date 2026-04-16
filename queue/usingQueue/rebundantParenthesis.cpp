#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> stockSpan(vector<int>prices){
    vector<int> ans;
    stack<pair<int,int>> s;
    for (auto price:prices){
        int days=1;
        while (! s.empty() && s.top().first<=price){
            days+=s.top().second;
            s.pop();
        }
        s.push({price,days});
        ans.push_back(days);
    }
    return ans;
}

int main() {
    vector<int>v={100,80,60,70,60,75,85};
    vector<int>ans=stockSpan(v);
    for (auto i : ans){
        cout<<i<<" ";
    }


}
