# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
//REVERSE A STRING 
void reverse_string(string s){
    if (s.length()==0) return ;
    string rest=s.substr(1);
    reverse_string(rest);
    cout<<s[0];
return ;
}

void replace_pi(string s){
    if (s.length()==0) return ;
    if (s[0]=='p' && s[1]=='i'){ 
        cout<<3.14;
        replace_pi(s.substr(2));
    }
    else{
        cout<<s[0];
        replace_pi(s.substr(1));
    }
}
void remove_duplicates(string s){
    if (s.length()==0) return ;
    if (s[0]!=s[1]) {
        cout<<s[0];
        remove_duplicates(s.substr(1));
    }
    else{
        remove_duplicates(s.substr(1));
    }
}
string push_x_last(string s){
    if (s.length()==0) {
        return "";
        }
    char ch=s[0];
    string ans=push_x_last(s.substr(1));
    if (ch=='x') return ans+ch;
    else{
        return ch+ans;
    }
}

void substring(string s, string ans){
    if (s.length()==0) {
        cout<<ans<<endl;
        return ;
    }
    char st=s[0];
    string rest=s.substr(1);
    substring(rest,ans);
    substring(rest,ans+st);
}
void subs_with_ascii(string s, string ans){
    if (s.length()==0){
        cout<<ans<<endl;
        return ;
    }
    char ch=s[0];
    string rest=s.substr(1);
    int code=ch;
    subs_with_ascii(rest,ans);
    subs_with_ascii(rest,to_string(code)+ans);
    subs_with_ascii(rest,ans+ch);
}
void permutation(string s, string ans){
    int count=0;
    if (s.length()==0) {cout<<ans<<endl; return ;}
    for (int i=0;i<s.length();i++){
        char ch=s[i];
        string rest=s.substr(0,i)+s.substr(i+1);
        permutation(rest,ans+ch);
    }
}
int countPath(int s,  int e){
    if (s==e){
        return 1;
    }
    if (s>e){
        return 0;
    }
    int count=0;
    for (int i=1;i<=6;i++){
        count+=countPath(s+i,e);
    }
    return count;
}
int ratInMaze(int e, int i , int j){
    if (e-1==i && e-1==j) return 1;
    if (i>=e || j>=e) return 0;
    return ratInMaze(e,i+1,j)+ratInMaze(e,i,j+1);
}
int countTiling(int n){
    if (n==0) return 0;
    if (n==1) return 1;
    return countTiling(n-2)+countTiling(n-1);
}
int friendsPairing(int n){
    if (n==0 || n==1 || n==2)  return n;
     return friendsPairing(n-1)+ friendsPairing(n-2)*(n-1);
}
int maxKnapsack(int value[], int wt[], int n,int w){
    if (n<=0 || w<=0) return 0;
    if (wt[n-1]>w) return maxKnapsack(value,wt , n-1, w);
    return max(maxKnapsack(value, wt,n-1, w-wt[n-1])+value[n-1],maxKnapsack(value,wt,n-1,w));
}
int main(){
//TIME COMPLEXITY=(total no of recursion calls )*(no of operations in each call)
// string s="ankit";
// reverse_string(s);

// string s="pipppiiiddsgpispdfipigfx";
// replace_pi(s);

// string s="aaabbbdddiiiisssjjj";
// remove_duplicates(s);

// string s="dfsdxxkasxlkhsdxlsxdixxl";
// cout<<push_x_last(s);

// string s="ABC";
// substring(s,"");
// subs_with_ascii(s,"");
// string s="a";
// char ans = 'a';
// int code=ans;//get ascii

// char ch='3';
// int ans=ch-'0';//convert character number to string number
// cout<<ans;
// string s="ANKIT";
// permutation(s,"");
// cout<<countPath(0,3);
// cout<<ratInMaze(3,0,0);
// cout<<countTiling(4);
// cout<<friendsPairing(4);
int wt[]={10,20,30};
int value[]={100,50,150};
cout<<maxKnapsack(value,wt,3,50);
    return 0;
}