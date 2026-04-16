#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define m1 cout << "-1" << endl
#define nline cout <<'\n'
#define input(arr)       \
    for (auto &it : arr) \
        cin >> it;
#define output(arr)     \
    for (auto it : arr) \
        cout << it << " ";\
        cout<<endl;
typedef std::vector<int> vi;
typedef std::vector<long long> vl;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
int find(string &s){
    int n = s.size();
    int carry = 0;
    for(int i = n-1; i >=0; i--){
        int curr = (s[i]-'0') * 2 + carry;
        s[i] = (curr % 10) + '0';
        carry = curr / 10;
    }
    return carry;
}

string toBinaryLeft(string &s) {
    if(s.empty()) return "0";
    ll num = stoll(s);
    if (num == 0) return "0";
    string result;
    while (num > 0) {
        result = (num & 1 ? '1' : '0') + result;
        num >>= 1;
    }
    return result;
}

string toBinaryRight(string &s){
    string ans = "";
    for(int i = 0; i < 23; i++){
        int t = find(s);
        if(t) ans += '1';
        else ans += '0';
    }
    return ans;
}

void solve(){
    string s; cin >> s;
    bool neg  = false;
    if(s[0] == '-'){
        s = s.substr(1);
        neg = true;
    }
    string left = "";
    string right = "";
    bool dot = false;
    for(char ch : s){
        if(ch == '.'){
            dot = true;
            continue;
        }
        if(dot) right += ch;
        else left += ch;
    }

    string ans = "";
    ans += (neg ? '1' : '0');
    ans += ' ';

    left = toBinaryLeft(left);
    right = toBinaryRight(right);

    int exponent = 0;

    if(left != "0" && !left.empty()){
        exponent = (int)left.size() - 1 + 127;
    }
    else{
        int leadingZ = 0;
        for(char bit : right){
            if(bit == '0') leadingZ++;
            else break;
        }
        exponent = 127 - (leadingZ + 1);
    }
    string tostring = to_string(exponent);
    string t = toBinaryLeft(tostring);
    t = string(8 - t.size(),'0') + t;
    ans += t + ' ';
    string mantissa = "";
    
    if(left != "0" && !left.empty()){
        mantissa = left.substr(1) + right;
    }
    else{
        int skip = 0;
        for(char bit : right){
            if(bit == '0') skip++;
            else break;
        }
        mantissa = right.substr(skip + 1);
    }

    if((int)mantissa.size() < 23){
        mantissa += string(23 - mantissa.size(), '0');}
    else{
        mantissa = mantissa.substr(0,23);}

    ans += mantissa;

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();

    return 0;
}
