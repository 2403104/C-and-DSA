# include <iostream>
# include <vector>
# include <algorithm>
# include <string>//optional (iostream contains this)
using namespace std;
string shortestPalindrome(string s) {
    int n=s.size();
    string rev=s;
    reverse(rev.begin(),rev.end());
    const char* a=rev.c_str();
    const char* b=s.c_str();
    for(int i=0;i<s.size();i++){
        if(memcmp(a+i,b,n-i)==0) return rev.substr(0,i)+s;
    }
    return "";
}
int main(){
// char str[]={'a','b','c','\0'};
// cout<<str<<endl;//with \0 it will be converted into string if \0 is at the lst of the char array
// cout<<sizeof(str)/sizeof(str[0]);//4

// char str[]="Ankit Kumar";//length will be 12 \0 will also be added at the last
// cout<<str<<endl;

// char str[100];//for empty string just fill the string size of the string 
// cin>>str;//it will ignore after a space(use ci.getline)
// char str[10];//it will be 10 after adding \0 at the last
// cin.getline(str,10,'.');//(char name, string length , delimiter(it will stop if you enter the defined character in the delimiter))
// cout<<str<<endl;

// char str[11];
// cin.getline(str,11);
// for (char ch: str){
//     cout<<ch<<" ";
// }


// char ch[]="ankit kumar";//can't change during runtime
// int count=0;
// for (int i=0;i<ch[i]!='\0';i++){
//     count++;
// }
// cout<<count;

// string st="ankit kumar";//dynamic in nature,contiguous
// cout<<st;
// string str1="Ankit ";
// string str2="Kumar";
// string str=str1+str2;//can be concatenated(not possible in character array)
// cout<<(str1==str2);
// cout<<str;  
// cout<<str.length();

// string str;
// getline(cin,str);//for string str
// cout<<str;



    return 0;
}