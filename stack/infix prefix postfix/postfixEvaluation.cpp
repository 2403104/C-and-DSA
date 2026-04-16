# include <iostream>
# include <stack>
# include <math.h>
using namespace std;
int evaluate(int a, int b, char c)
{
    if (c=='+') return a+b;
    if (c=='-') return a-b;
    if (c=='*') return a*b;
    if (c=='/') return a/b;
}
int postfixEvaluation(string s)
{
    stack<int> st;
    for (int i=0;i<s.length();i++){
        if (s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op2=st.top();
            st.pop();
            int op1=st.top();
            st.pop();
            st.push(evaluate(op1,op2,s[i]));
        }
    }
    return st.top();
}
int main(){

    string s="46-2/5*7+";
    cout<<postfixEvaluation(s);


    return 0;
}