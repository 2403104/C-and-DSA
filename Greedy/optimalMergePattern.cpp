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
    vector<int> v={5,2,4,7};
    int n=4;
    priority_queue<int,vector<int>,greater<int>>minHeap;
    for (int i=0;i<v.size();i++){
        minHeap.push(v[i]);
    }
    int ans=0;
    while(minHeap.size()>1){
        int e1=minHeap.top();
        minHeap.pop();
        int e2=minHeap.top();
        minHeap.pop();
        ans=ans+e1+e2;
        minHeap.push(e1+e2);
    }
    cout<<ans;

    return 0;
}