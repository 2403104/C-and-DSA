#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;//policy based data structure
using ordered_set = tree<int , null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;//typename, mapped_type, comparision_function, underlaying tree (red black tree), node update policy for order statistics
//namespace out (for custom debugging ,inputting and printing framework)
namespace out{
    template<typename t, typename s>
    ostream& operator << (ostream&cout, const pair<t,s>&pi){
        return cout<<endl<<pi.first<<' '<<pi.second;
    }
    
    template<typename t>
    ostream &operator << (ostream&cout, vector<t>a){
        bool sp=0;
        for(t it : a){
            if(sp) cout<<" ";
            sp=1;
            cout<<it;
        }
        return cout;
    }
    template<typename t, typename s>
    ostream& operator << (ostream& cout, const map<t, s> mp) {
        for(auto i : mp) cout << i << '\n';
        return cout;
    }
    template<typename t>
    ostream& operator << (ostream& cout, set<t> a) {
        bool sp = 0;
        for(t i : a) {
            sp = 1;
            cout << i << ' ';
        }
        return cout;
    }
    ostream & operator << (ostream &cout, __int128 a){
        if(a==0){
            cout<<0;
            return cout;
        }
        string s="";
        while(a>0){
            int rem=a%10;
            a/=10;
            s=char(rem+'0')+s;
        }
        cout<<s;
        return cout;
    }
    template<typename t, typename s>
    string to_string(pair<t,s>p){
        return "{"+to_string(p.first)+','+to_string(p.second)+"}";
    }
    template<typename t>
    string to_string(vector<t> a) {
        string a22 = "[";
        bool sep = 0;
        for(t i : a) {
            if(sep) a22 += ", ";
            sep = 1;
            a22 += to_string(i);
        }
        a22 += "]";
        return a22;
    }
    template<typename other>
    string to_string(other oth) {
        string a22 = "[";
        bool spac = 0;
        for(auto i : oth) {
            if(spac) a22 += ", ";
            spac = 1;
            a22 += to_string(i);
        }
        return a22 + "]";
    }
    string to_string(bool x){
        return x ? "true":"0";
    }
    string to_string(const string s){
        return "\""+s+"\"";
    }
    string to_string(const char& c) {
        string a22;
        a22 += c;
        return "\'" + a22 + "\'";
    }
    template<typename t, typename s>
    istream &operator >> (istream &cin, pair<t,s>&p){
        return cin>>p.first>>p.second;
    }
    template<typename t>
    istream &operator >> (istream &cin, vector<t>&arr){
        for(t &it : arr) cin>>it;
        return cin;
    }
};
//(A*X)%m=1 means find X such that when multiplied by A and taken modulo with m gives remainder 1   (A,m should be coprime)
template <typename T>
struct Triplet{
    T x,y,gcd;
};
template <typename T>
Triplet<T> ExtendedEuclid(T a, T b){
    if(b==0){
        Triplet ans;
        ans.x=1;
        ans.y=0;
        ans.gcd=a;
        return ans;
    }
    Triplet smallAns=ExtendedEuclid(b,a%b);
    Triplet ans;
    ans.x=smallAns.x;
    ans.gcd=smallAns.gcd;
    ans.y=smallAns.x-(a/b)*smallAns.y;
    return ans;
}
template<typename T>
T multiplicativeInverseModulo(T a, T m){
    Triplet ans=ExtendedEuclid(a,m);
    return ans.x;
}
template <typename T>
class Modular{
public:
    using Type=typename decay<decltype(T::value)>::Type;//declaration type gives the type of value in class(like const long  long ) , dectype will remvoe all those cv , references will give like (long long , int )
    
};
int main(){
    // ordered_set os;
    // os.insert(10);
    // os.insert(18);
    // os.insert(85);
    // os.insert(8);
    // for(auto it : os) cout<<it<<' ';

    using out::operator<<;//scope 
    using out::operator>>;//scope 
    // pair<int,int>p;
    // vector<int>arr(4);
    // vector<string>st={"asdfj","kadsjfakdj","asdjf"};
    

    return 0;
}
