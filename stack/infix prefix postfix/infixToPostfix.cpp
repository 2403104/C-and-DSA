# include <iostream>
# include <stack>
using namespace std;
int precedence(char c){
    if (c=='^') return 3;
    if (c=='/' || c=='*') return 2;
    if (c=='+' || c=='-') return 1;
    return -1;
}
string infixToPostfix(string s){
    stack<char>st ;
    string ans="";
    for (int i=0;i<s.length();i++){
        if ((s[i]>='0' && s[i]<='0') || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')) ans+=s[i];
        else if(s[i]=='(') st.push(s[i]);
        else if (s[i]==')'){
            while(!st.empty() && st.top()!='(' ){
                ans+=st.top();
                st.pop();
            }
                if (!st.empty()) st.pop();
        }
        else {
            while (!st.empty() && (precedence(st.top())>precedence(s[i]))){

            ans+=st.top();
            st.pop();
            }
        st.push(s[i]);
        }
    }
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}
int main(){

    string s="(a-b/c)*(a/k-l)";
    cout<<infixToPostfix(s);

    return 0;
}