#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    vector<vector<int>> v = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    sort(v.begin(), v.end(), [](vector<int> &a, vector<int> &b)
         { return a[1] < b[1]; 
    });
    int n = v.size();
    for(int i=0;i<n;i++){
        cout<<v[i][0]<<" "<<v[i][1]<<endl;
    }
    int ans = 1;
    int endTime=v[0][1];
    for(int i=1;i<n;i++){
        if(v[i][0]>=endTime ){
            ans++;
            endTime=v[i][1];
        }
    }
    cout<<n-ans;
    return 0;
}