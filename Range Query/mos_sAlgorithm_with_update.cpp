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
    int l, r, t, idx;
};
struct Update{
    int pos, preVal, newVal;
};
int BLOCK;
vi arr;

void solve(){
    int n, q; cin >> n >> q;
    arr.resize(n);
    vi origArr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        origArr[i] = arr[i];
    }

    vector<pair<int, pair<int,int>>> ops;
    vector<int> comp = arr;

    for(int i = 0; i < q; i++){
        int type; cin >> type;
        if(type == 1){
            int k, u; cin >> k >> u; k--;
            ops.push_back({1, {k, u}});
            comp.push_back(u);
        } else {
            int a, b; cin >> a >> b; a--; b--;
            ops.push_back({2, {a, b}});
        }
    }
    sort(all(comp));
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    auto getId = [&](int x){
        return lower_bound(all(comp), x) - comp.begin();
    };
    for(int i = 0; i < n; i++){
        arr[i] = getId(arr[i]);
        origArr[i] = arr[i];
    }
    vector<Update> updates;
    vector<Query> queries;
    for(auto &it : ops){
        if(it.first == 1){
            int pos = it.second.first;
            int newVal = getId(it.second.second);
            updates.push_back({pos, arr[pos], newVal});
            arr[pos] = newVal;
        }else{
            int l = it.second.first;
            int r = it.second.second;
            queries.push_back({l, r, (int)updates.size(), (int)queries.size()}); // {l, r, number of updates performed so far, the query index}
        }
    }
    arr = origArr;
    int distinct = 0;
    vi freq(comp.size()+1, 0);
    auto add = [&](int pos){
        int v = arr[pos];
        if(++freq[v] == 1) distinct ++;
    };
    auto remove = [&](int pos){
        int v = arr[pos];
        if(--freq[v] == 0) distinct --;
    };
    auto applyUpdate = [&](const Update &u, int currL, int currR){
        int pos = u.pos;
        if(currL <= pos && pos <= currR){
            remove(pos);
            arr[pos] = u.newVal;
            add(pos);
        }else{
            arr[pos] = u.newVal;
        }
    };
    auto rollbackUpdate = [&](const Update &u, int currL, int currR){
        int pos = u.pos;
        if(currL <= pos && pos <= currR){
            remove(pos);
            arr[pos] = u.preVal;
            add(pos);
        }else{
            arr[pos] = u.preVal;
        }
    };
    BLOCK = max(1, (int)pow(n, 0.6666667));
    sort(all(queries), [&](const Query &A, const Query &B){
        if(A.l / BLOCK != B.l / BLOCK) return A.l / BLOCK < B.l / BLOCK;
        if(A.r / BLOCK != B.r / BLOCK) return A.r / BLOCK < B.r / BLOCK;
        return A.t < B.t;
    });
    
    vector<string>ans(queries.size());
    int currL = 0, currR = -1, timeNow = 0;
    for(auto &qr : queries){
        int L = qr.l;
        int R = qr.r;
        int T = qr.t;
        while(timeNow < T){
            applyUpdate(updates[timeNow], currL, currR);
            timeNow++;
        }
        while(timeNow > T){
            timeNow--;
            rollbackUpdate(updates[timeNow], currL, currR);
        }
        while(currL > L){
            currL--;
            add(currL);
        }
        while(currR < R){
            currR++;
            add(currR);
        }
        while(currL < L){
            remove(currL);
            currL++;
        }
        while(currR > R){
            remove(currR);
            currR--;
        }     
        if((R - L + 1) == distinct) {
            ans[qr.idx] = "YES";
        }else{
            ans[qr.idx] = "NO";
        }
    }
    for(auto &str : ans){
        cout << str << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}