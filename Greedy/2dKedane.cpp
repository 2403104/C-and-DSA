#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define input(arr) for(auto &it : arr) cin >> it;
#define output(arr) do { for (auto &it : arr) cout << it << ' '; cout << endl; } while(0);

int maxVal(vector<int> &arr){
        int curr = 0;
        int mx = INT_MIN;
        for(int i = 0; i < arr.size(); i++){
                curr += arr[i];
                mx = max(mx, curr);
                if(curr < 0) curr = 0;
        }
        return mx;
}

int maxCrossing(vector<vector<int>> &arr, int lo, int mid, int hi){
        int mx = INT_MIN;
        int n = arr.size();
        vector<int> temp(n, 0);
        for(int l = mid;  l >= lo; l--){
                temp.assign(n, 0);
                for(int r = l; r <= hi; r++){
                        for(int i = 0; i < n; i++){
                                temp[i] += arr[i][r];
                        }
                        mx = max(mx, maxVal(temp));
                }
        }
        return mx;
}

int findSum(vector<vector<int>>  &arr, int lo, int hi){
        if(lo > hi) return INT_MIN;
        if(lo == hi) {
                int mx = INT_MIN;
                int curr = 0;
                for(int i = 0; i < arr.size(); i++){
                        curr += arr[i][lo];
                        mx = max(mx, curr);
                        if(curr < 0) curr = 0;
                }
                return mx;
        }
        int mid = (lo + hi) / 2;
        int left = findSum(arr, lo, mid);
        int right = findSum(arr, mid + 1, hi);
        int cross = maxCrossing(arr, lo, mid, hi);
        return max({left, right, cross});
}

int main(){
    vector<vector<int>> mat = {
    { 1,  2, -1, -4, -20},
    {-8, -3,  4,  2,   1},
    { 3,  8, 10,  1,   3},
    {-4, -1,  1,  7,  -6}
    };

    int n = mat.size();
    int m = mat[0].size();

    cout << findSum(mat, 0, m - 1) << endl;

    return 0;
}