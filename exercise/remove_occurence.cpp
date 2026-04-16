# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
//  string.find(substring) give the first occurence of first string
//  string .erase(start,end)
int main(){

// string s="kumarankit ";
// string sub="ankit";
// cout<<s.find(sub)<<endl;//give the index from which sub starts in the s
// s.erase(s.find(sub),sub.length());//curr position , next no of element
// cout<<s;

// string s="daabcbaabcbc";
// string sub="abc";
// while (s.length()>0 && s.find(sub)<s.length()){
//     s.erase(s.find(sub),sub.length());
// }
// cout<<s;

// s.erase(s.find(sub),3);
// cout<<s;

// vector<int> v={4,2,2,3,4,5,5,5,6,9,9,9,8};
// vector<int>ans={v[0]};
// for (int i=0;i<v.size();i++){
//     int flag=true;
//     for (int j=0;j<ans.size();j++){
//         if (ans[j]==v[i]){
//             flag=false;
//             break;
//         }
//     }
//         if (flag){
//             ans.push_back(v[i]);
//         }
// }
// for (int j=0;j<ans.size();j++){
//     cout<<ans[j]<<" ";
// }

//    vector<int> v = {1, 2, 3, 4, 5};

//     // Remove the element at index 2
//     v.erase(v.begin() + 2);

//     for (auto i : v)
//         cout << i << " ";
    return 0;
}