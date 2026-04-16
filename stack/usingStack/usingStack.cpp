# include <iostream>
# include <stack>
using namespace std;
void reverseString(string s){
    stack<string> st;
    for (int i=0;i<s.length();i++){
        string p="";
        while (s[i]!=' ' && i<s.length()){
            p+=s[i];
            i++;
        }
        st.push(p);
    }
    while (!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;

}
int main(){

    string s="Hey, I have qualified JEE";

    reverseString(s);


    return 0;
}