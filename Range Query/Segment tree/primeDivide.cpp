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
const int SIZE = 1e5+5;
int arr[SIZE];
int getIdx(int num){
    if(num == 2) return 0;
    else if(num == 3) return 1;
    else if(num == 5) return 2;
    return -1;
}
int seg[SIZE*4][3];
void push(int idx, int l, int r){
    if(l != r){
        for(int i = 0; i <= 2; i++){
            seg[idx * 2 + 1][i] += seg[idx][i];
        }
        for(int i = 0; i <= 2; i++){
            seg[idx * 2 + 2][i] += seg[idx][i];
        }
    }else{
        while(arr[l] % 2 == 0 && seg[idx][0] > 0){
            arr[l] /= 2;
            seg[idx][0] --;
        }
        while(arr[l] % 3 == 0 && seg[idx][1] > 0){
            arr[l] /= 3;
            seg[idx][1] --;
        }
        while(arr[l] % 5 == 0 && seg[idx][2] > 0){
            arr[l] /= 5;
            seg[idx][2] --;
        }
    }
    fill(seg[idx], seg[idx] + 3, 0);
}
void pushAll(int idx, int l, int r){
    push(idx, l, r);
    if(l == r) return;
    int mid = (l + r) / 2;
    pushAll(idx * 2 + 1, l, mid);
    pushAll(idx * 2 + 2, mid + 1, r);
}
void updateRange(int idx, int l, int r, int ul, int ur, int primeIdx){
    if(r < ul || l > ur) return;
    if(ul <= l && r <= ur) {
        seg[idx][primeIdx]++;
        return;
    }
    push(idx, l, r);
    int mid = (l + r)/2;
    updateRange(idx * 2 + 1, l, mid, ul, ur, primeIdx);
    updateRange(idx * 2 + 2, mid + 1, r, ul, ur, primeIdx);
}
void updatePoint(int idx, int l, int r, int pos, int val){
    push(idx, l, r);
    if(l == r){
        arr[pos] = val;
        return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid) updatePoint(idx * 2 + 1, l, mid, pos, val);
    else updatePoint(idx * 2 + 2, mid + 1, r, pos, val);
}
void solve(){
    int n; cin >> n;
    memset(seg, 0, sizeof(seg));
    for(int i=0;i<n;i++) cin >> arr[i];
    int q; cin >> q; 
    while(q--){
        int type; cin >> type;
        if(type == 1){
            int l, r, p; cin >> l >> r >> p;l--, r--;
            int primeIdx = getIdx(p);
            if(primeIdx == -1) continue;
            updateRange(0, 0, n-1, l, r, primeIdx);
        }else{
            int idx, val; cin >> idx >> val; idx --;
            updatePoint(0, 0, n-1, idx, val);
        }
    }
    pushAll(0, 0, n-1);
    for(int i = 0; i < n; i++) cout << arr[i] << ' ';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}