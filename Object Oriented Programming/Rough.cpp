#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define m1 cout << "-1" << endl
#define input(arr) for(auto &it : arr) cin >> it;
#define output(arr) do { for (auto &it : arr) cout << it << ' '; cout << endl; } while(0);
typedef std::vector<int> vi;
typedef std::vector<long long> vl;
typedef std::vector<vi> vvi;
void solve(){
    int n; cin >> n;
    vector<int> ans;
    set<int>st;
    function<void(int, int, vector<int>&, set<int>&)> dfs = [&](int x, int B, vector<int>&curr, set<int>&cst){
        if(x > ((1 << n) - 1) || (B > n)) return;
        if(!cst.count(x)){
            curr.push_back(x);
            cst.insert(x);
        }
        int m = (1 << B);
        dfs(x | m, B + 1, curr, cst);
        dfs(x, B + 1, curr, cst );
    };
    for(int i = n; i >= 2; i--){
        int T = (1 << i) - 1;
        int B = (31 - __builtin_clz(T));
        vector<int>curr;
        set<int>cst;
        dfs(T, B + 1, curr, cst);
        sort(all(curr));
        for(int i = 0; i < curr.size(); i++){
            if(!st.count(curr[i])) ans.push_back(curr[i]);
            st.insert(curr[i]);
        }

    }
    for(int i = 1; i < (1 << n); i++){
        if(i % 2 != 0 && st.find(i) == st.end()){
            ans.push_back(i);
            st.insert(i);
        }
    }
    for(int i = 0; i < (1 << n); i++){
        if(st.find(i) == st.end()){
            ans.push_back(i);
            st.insert(i);
        }
    }
    output(ans);

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}