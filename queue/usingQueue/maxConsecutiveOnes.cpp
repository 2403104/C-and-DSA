#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int countOnes(vector<int>v, int k){
    int ans=0;
    for (int i=0;i<v.size();i++){
        int curr=0;
        int j=i;
        int temp=k;
        while (j<v.size() && (temp>0 || v[j]==1)){
            if (v[j]==0){
                temp--;
                curr++;
            }
            else if (v[j]==1){
                curr++;
            }
            j++;
        }
        ans=max(ans,curr);
    }
    return ans;
}

int main() {
    vector<int>v={0,0,1,1,0,0,1,1,1,0,1,1,0,0,1,1,1,1};
    cout<<countOnes(v,3);

}
