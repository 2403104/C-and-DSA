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
int prefixEvaluation(string s)
{
    stack<int> st;
    for (int i=s.length()-1;i>=0;i--){
        if (s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int op1=st.top();
            st.pop();
            int op2=st.top();
            st.pop();
            st.push(evaluate(op1,op2,s[i]));
        }
    }
    return st.top();
}
int main(){

    string s="-+7*45+20";
    cout<<prefixEvaluation(s);


    return 0;
}