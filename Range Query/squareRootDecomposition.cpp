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
class SquareRootDecomposition{
    vi arr;
    vi blocks;
    int n;
    int blockSize;
public:
    SquareRootDecomposition(const vi &arr){
        this -> arr = arr;
        this -> n = arr.size();
        blockSize = (int)sqrt(n);
        blocks.resize((n + blockSize - 1) / blockSize, 0 );
        for(int i = 0; i < n; i ++){
            blocks[i / blockSize] += arr[i];
        }
    }
    void update(int idx, int val){
        int blockIdx = idx / blockSize;
        blocks[blockIdx] = blocks[blockIdx] - arr[idx] + val;
        arr[idx]  = val;
    }
    ll query(int l, int r){
        ll sum = 0;
        int stB = l / blockSize;
        int enB = r / blockSize;
        if(stB == enB){
            for(int i = l; i <= r; i ++) {
                sum += arr[i];
            }
        }else{
            for(int b = stB + 1; b <= enB - 1; b++) sum += blocks[b];
            for(int i = l; i <= (stB + 1) * blockSize - 1; i++) sum += arr[i];
            for(int i = enB * blockSize; i <= r; i++) sum += arr[i];
        }
        return sum;
    }
};

void solve(){
    vi arr = {1,2,4,5,7,8,6,3,2,1,4,5};
    SquareRootDecomposition inst(arr);
    int n = arr.size();
    cout << inst.query(0, n-1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();

    return 0;
}

/*

*/