# include <iostream>
# include <algorithm>
# include <vector>
# include <stack>
using namespace std;
int main(){
    string s;
    cin>>s;
    stack<int>st;
    int n=s.length();
    char sign='+';
    for(int i=0;i<n;i++){
        if(s[i]=='+'|| s[i]=='-'){
            sign=s[i];
        } 
        int num=0;
        if(isdigit(s[i])){
            while(i<n && isdigit(s[i])){
                num=num*10+s[i]-'0';
                i++;
            }
            i--;
        }
        if(num>0){
            if(sign=='-'){
                num*=-1;
            }
            st.push(num);
        }
        
    }
    int ans=0;
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    cout<<ans;
    return 0;
}