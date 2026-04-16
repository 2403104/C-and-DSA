# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int main(){
// string s="ankitkumar";
// reverse(s.begin(),s.end());
// cout<<s;

string s=" Hello World ";
reverse(s.begin(),s.end());
string ans="";
for (int i=0;i<s.length();i++){
    string word="";
    while (i<s.length() && s[i]!=' '){
        word+=s[i];
        i++;
    }
    reverse(word.begin(),word.end());
    if (word.length()>0) ans+=word+" ";;
}
cout<<ans;

    return 0;
}