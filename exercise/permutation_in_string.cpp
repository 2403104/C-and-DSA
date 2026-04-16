# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
bool isFreqSame(int c[],int d[]){
    for (int  i=0;i<25;i++){
        if (c[i]!=d[i]){
            return false;
        }
    }
    return true;
}
bool checkpermutation(string a, string b){
    //  to find b
    int freq[26]={0};
    for (int i=0;i<b.length();i++){
        freq[b[i]-'a']++;
    }
    for (int i=0;i<a.length();i++){
    int freq_[26]={0};
    for (int j=i;j<i+b.length();j++){
        freq_[a[j]-'a']++;
    }
    if (isFreqSame(freq,freq_)) return true;
    }
    return false;
    }

int main(){
// on subbtracting char from char (it gives their ascii difference (in memory it get converted innto ascii))

//     int freq[26]={0};
// for (int i=0;i<26;i++){
//     cout<<freq[i]<<" ";
// }
string a="eidbcaooo";
string b= "abcoo";
cout<<checkpermutation(a,b);

    return 0;
}