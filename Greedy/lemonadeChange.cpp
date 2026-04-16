# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;

bool solve(vector<int>&bills){
    unordered_map<int,int>mp;
    int n=bills.size();
    for(int i=0;i<n;i++){
        if(bills[i]==5) mp[bills[i]]++;
        else if (bills[i]==10){
            mp[bills[i]]++;
            if(mp[5]>0) mp[5]--;
            else return false;
        }
        else if(bills[i]==20){
            mp[bills[i]]++;
            if(mp[5]>=3){
                mp[5]-=3;
            }else if(mp[5]>=1 &&  mp[10]>=1){
                mp[5]--;
                mp[10]--;
            }
            else return false;
        }
    }
    return true;
}

int main(){
    vector<int>bills={5,5,10,10,20};

    cout<<solve(bills);

    return 0;
}