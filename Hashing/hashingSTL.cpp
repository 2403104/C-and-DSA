// STL = Standard Template  Library

/*
                         Maps                                    Unordered Maps
Insertion                log(n)                                    O(1)
Accessing                log(n)                                      O(1)
implement using         red black tree                              hash map
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

#define vi vector<int>;
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

int main()
{

    // map<int,int> m;//<key data type , value data type>
    // vector<int> v = {
    //     2,
    //     4,
    //     2,
    //     1,
    //     3,
    //     8,
    // };
    // map<int, int> freq;
    // rep(i, 0, v.size())
    // {
    //     freq[v[i]]++;
    // }
    // map<int, int>::iterator it; // it is iterator
    // for (it = freq.begin(); it != freq.end(); it++)
    // {
    //     cout << it->first << "->" << it->second << endl;
    // }

    vector<int> v={5,4,1,2,8,7,6,3,9};
    string s="aankitkumankit";
    cout<<s.find('k');
    return 0;
}