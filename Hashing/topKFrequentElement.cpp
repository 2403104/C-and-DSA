#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

int main() {
    vector<int> v = {1, 2, 2, 2, 3, 4};
    map<int, int> m;
    int k = 2;
    for (int i = 0; i < v.size(); i++) {
        if (m[v[i]] == 0 && k+1 == m.size()) break;
        m[v[i]]++;
    }
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        cout << it->first << "->" << it->second << endl;
    }

    return 0;
}
