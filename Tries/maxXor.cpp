# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;

class TrieNode{
    public:
    TrieNode* next[2];
    TrieNode(){
        next[0]=NULL;
        next[1]=NULL;
    }
};
TrieNode* buildTrie(vector<int>&a){
    TrieNode* root=new TrieNode();
    int n=a.size();
    for(int i=0;i<n;i++){
        int num=a[i];
        TrieNode* it=root;
        for(int i=31;i>=0;i--){//start with most significant bit to least significant bit
            int bit=(num>>i)&1;
            if(it->next[bit]==NULL){
                it->next[bit]=new TrieNode();
            }
            it=it->next[bit];
        }
    }
    return root;
}
int helper(TrieNode* root, vector<int>&a){
    int res=0;
    for(int i=0;i<a.size();i++){
        int num=a[i];
        TrieNode* it=root;
        int currMax=0;
        for(int i=31;i>=0;i--){
             int bit=((num>>i)&1)?0:1;//if that is zero then go to one else go to one
             if(it->next[bit]) { // If the opposite bit exists in Trie
                currMax <<= 1; // Shift left to make space for the new bit
                currMax |= 1;  // Set the last bit to 1 (since we found the preferred bit)
                it = it->next[bit]; // Move to the next node
            }            
            else {
                currMax <<= 1; // Shift left, making space for the new bit
                currMax |= 0;  // Set the last bit to 0 (since we didn't find the preferred bit)
                it = it->next[bit xor 1]; // Move to the available node (less optimal)
            }
            
        }
        res=max(res,currMax);
    }
    return res;
}
int main(){
    vector<int> a={3,10,5,15,2};
    TrieNode* root=buildTrie(a);
    int ans=helper(root,a);
    cout<<ans;
    return 0;
}