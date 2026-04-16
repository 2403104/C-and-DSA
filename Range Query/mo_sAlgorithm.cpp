#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define m1 cout << "-1" << endl
#define input(arr) for(auto &it : arr) cin >> it;
#define output(arr) do { for (auto &it : arr) cout << it << ' '; cout << endl; } while(0);
typedef std::vector<int> vi;
typedef std::vector<long long> vl;
typedef std::vector<bool> vb;
typedef std::vector<vi> vvi;
struct Query{
    int l, r, idx;
};
int block;
bool compare(Query a, Query b){
    if(a.l / block != b.l / block) return a.l / block < b.l / block;
    return a.r < b.r;
}
const int MAXI = 2*1e5+5;
void solve(){
    int n, q;
    cin >> n >> q;
    vi arr(n);
    for(auto &it : arr) cin >> it;
    block = (int)sqrt(n);
    vector<Query> query(q);
    for(int i = 0; i < q; i++){
        int l, r; cin >> l >> r; l --, r --;
        query[i] = {l, r, i};
    }
    sort(query.begin(), query.end(),  compare);
    vector<int>freq(MAXI, 0);
    vector<int> ans(q);
    int currL = 0, currR = -1, distinct = 0;
    auto add = [&](int x){
        if(++freq[x] == 1) distinct ++;
    };
    auto remove = [&](int x){
        if(--freq[x] == 0) distinct --;
    };
    for(auto &qr : query){
        int L = qr.l;
        int R = qr.r;
        while(currL > L) add(arr[--currL]);
        while(currR < R) add(arr[++currR]);
        while(currL < L) remove(arr[currL++]);
        while(currR > R) remove(arr[currR++]);
        ans[qr.idx] = distinct;
    }
    output(ans);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}










// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define ull unsigned long long
// #define all(x) (x).begin(), (x).end()
// #define rall(x) (x).rbegin(), (x).rend()
// #define yes cout << "YES" << endl
// #define no cout << "NO" << endl
// #define m1 cout << "-1" << endl
// #define input(arr) for(auto &it : arr) cin >> it;
// #define output(arr) do { for (auto &it : arr) cout << it << ' '; cout << endl; } while(0);
// typedef std::vector<int> vi;
// typedef std::vector<long long> vl;
// typedef std::vector<bool> vb;
// typedef std::vector<vi> vvi;
// struct Query{
//     int l, r, idx;
// };
// const int block = 700;
// bool compare(Query a, Query b){
//     if(a.l / block != b.l / block) return a.l / block < b.l / block;
//     return a.r/block < b.r/block;
// }
// const int MAXI = 1e6+5;
// const int N = 3e5;
// ll arr[N];
// void solve(){
//     int n, k; cin >> n >> k;
//     for(int i = 0; i < n; i++) cin >> arr[i];
//     // block = (int)sqrt(n);
//     vector<Query> query(k);
//     for(int i = 0; i < k; i++){
//         int l, r; cin >> l >> r; l --, r --;
//         query[i] = {l, r, i};
//     }    
//     sort(query.begin(), query.end(), compare);
//     vector<int>freq(MAXI, 0);
//     vector<ll>ans(k, 0);
//     int currL = 0, currR = -1;
//     ll curr = 0;
//     auto add = [&](ll x){
//         ll prev = freq[x];
//         curr -= 1LL * prev * prev * x;
//         freq[x]++;
//         curr += 1LL * freq[x] * freq[x] * x;
//     };
//     auto remove = [&](ll x){
//         ll prev = freq[x];
//         curr -= 1LL * prev * prev * x;
//         freq[x]--;
//         curr += 1LL * freq[x] * freq[x] * x;
//     };
//     for(auto &qr : query){
//         int L = qr.l;
//         int R = qr.r;
//         while(currL > L) add(arr[--currL]);
//         while(currR < R) add(arr[++currR]);
//         while(currL < L) remove(arr[currL++]);
//         while(currR > R) remove(arr[currR--]);
//         ans[qr.idx] = curr;
//     }
//     for(auto &it : ans) cout << it << '\n';
// }
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(0);
    
//     solve();

//     return 0;
// }