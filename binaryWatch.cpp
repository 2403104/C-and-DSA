# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
# include <bitset>
using namespace std;

class Solution {
    public:
        
        vector<string> readBinaryWatch(int turnedOn) {
            vector<string>ans;
            for(int i=0;i<12;i++){
                for(int j=0;j<60;j++){
                    if(bitset<4>(i).count()+bitset<6>(j).count()==turnedOn){
                        string time=to_string(i) +":"+(j<10 ? "0":"")+to_string(j); 
                        ans.push_back(time);
                    }
                }
            }
            return ans;
        }
    };
int main(){

    return 0;
}