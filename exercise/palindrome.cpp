# include <iostream>
# include <vector>
# include <algorithm>
# include <string>
bool isAlphaNumeric(char ch){
    if ((ch>=0 && ch<=9) || (tolower(ch)>='a' &&  tolower(ch)<='z')) return true;
    return false;
}
bool validPalindrome(string s){
    int st=0, end=s.length()-1;
    while(st<end){
        if (! isAlphaNumeric(s[st])) {
            st++;
        continue;}
        if (! isAlphaNumeric(s[end])) {
            end--;
            continue;}
        if (tolower(s[st])!=tolower(s[end])) return false;
st++,end--;
    
    }
    return true;

}
using namespace std;
int main(){
char ch='a';
cout<<tolower(ch);
// string s="Ac3e3c&a";
// cout<<validPalindrome(s);
    return 0;
}