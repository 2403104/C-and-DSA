#include <bits/stdc++.h>
using namespace std;
/*given a start word and given a target word , change one char in each word such 
that the formed word should lie in the given lwordList , find the minimum number 
of changes needed to reach the final word
*/
class Solution {
public:
    int ladderLength(string st, string en, vector<string>& wordList) {
        queue<pair<string,int>>q;
        unordered_set<string>lst(wordList.begin(),wordList.end());
        q.push({st,1});
        unordered_set<string>vis;
        vis.insert(st);
        int n=st.size();
        while(!q.empty()){
            auto [word,cnt]=q.front();
            q.pop();
            if(word==en) return cnt;
            for(int i=0;i<n;i++){
                for(char ch='a';ch<='z';ch++){
                    string curr=word;
                    curr[i]=ch;
                    if(lst.find(curr)!=lst.end() && vis.find(curr)==vis.end()){
                        q.push({curr,cnt+1});
                        vis.insert(curr);
                    }
                }
            }
        }
        return 0;
    }
};

int main(){

    return 0;
}

