# include <iostream>
# include <stack>
using namespace std;
bool check(char a, char b){
    if ((a=='(' && b==')')||b=='(' && a==')') return true;
    if ((a=='[' && b==']')||b==']' && a=='[') return true;
    if ((a=='{' && b=='}')||b=='}' && a=='{') return true;
    return false;
}
bool balancedParenthesis(string s){
    stack<char>st;
    bool ans=true;
    for (int i=0;i<s.length();i++){
        if ((s[i]=='(') || (s[i]=='[') || (s[i]=='{')) st.push(s[i]);
        else if (s[i]=='{'){
            if (!st.empty() &&st.top()=='}'){
                st.pop();
            }else{
                ans=false;
                break;
            }
        }
        else if (s[i]=='('){
            if (!st.empty() && st.top()==')'){
                st.pop();
            }else{
                ans=false;
                break;
            }
        }
        else if (s[i]=='['){
            if (!st.empty() &&st.top()==']'){
                st.pop();
            }else{
                ans=false;
                break;
            }
        }
    }
    if(!st.empty()) return ans=false;
    return ans;
}
int main(){
    string s="{[{()}(])}";
    cout<<balancedParenthesis(s);
    return 0;
}