#include<bits/stdc++.h>
using namespace std;
template <typename T>
T add(T x, T y){ return x + y; }
int main(){

    // cout<<add(2.523,6.12)<<endl;
    // cout<<add(3,4)<<endl;
    // cout<<add("Ankit "s, "Kumar"s)<<endl;
    
    // cout<<add<float>(3.26,3.63)<<endl;
    // cout<<add<string>("Ankit ", "Kumar")<<endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

void QUICK_SORT(int low, int high, vector<int> copy) {
    if (low >= high) return;

    int mid = low + (high - low) / 2;
    int pivot = copy[mid];

    int left = low;
    int right = high;

    for (int i = low; i <= high; ++i) {
        if (i == mid) continue;
        if (copy[i] <= pivot) arr[left++] = copy[i];
        else arr[right--] = copy[i];
    }

    arr[left] = pivot;

    QUICK_SORT(low, left - 1, arr);
    QUICK_SORT(left + 1, high, arr);
}

int main() {
    int n;
    cin >> n;
    arr.resize(n);
    for (auto &num : arr) cin >> num;
    QUICK_SORT(0, n - 1, arr);
    for (auto &num : arr) cout << num << " ";
}
