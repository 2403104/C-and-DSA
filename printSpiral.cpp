#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define per(i, b, a) for (int i = b - 1; i >= a; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define input(arr)       \
    for (auto &it : arr) \
        cin >> it;
#define output(arr)     \
    for (auto it : arr) \
        cout << it << " ";
#define pb push_back
#define p push
#define F first
typedef std::vector<int> vi;
typedef std::vector<long long> vl;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<vi> vvi;
typedef std::pair<int, int> pii;
typedef std::vector<pii> vpii;
bool check(int i, int j, int n)
{
    return 0 <= i < n && 0 <= j < n;
}
void solve()
{
    int n;
    cin >> n;
    vvi ans(n, vi(n, -1));
    int x, y;
    if (n % 2 != 0)
    {
        x = n / 2;
        y = n / 2;
    }
    else
    {
        x = n / 2 - 1;
        y = n / 2 - 1;
    }

    ans[x][y] = 0;
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};
    int val = 1;
    int step = 1;
    while (val < n * n)
    {
        for (int d = 0; d < 4; d++)
        {
            int curr = step;
            step += d % 2;
            for (int j = 0; j < curr; j++)
            {
                x += dx[d];
                y += dy[d];
                if(check(x,y,n)){
                    ans[x][y]=val++;
                }
                if(val>=n*n) break;
            }
            if(val>=n*n) break;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    int t;
    cin >> t;
    // t=1;
    while (t--)
    {
        solve();
    }

    return 0;
}