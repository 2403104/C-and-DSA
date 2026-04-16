#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

bool check(string s)
{
    int n = s.size();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
                return false;
            st.top();
        }
    }
    return st.size() == 0;
}
bool check2(string s)
{
    int cnt = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            cnt++;
        else if (s[i] == ')')
            cnt--;
        if (cnt < 0)
            return false;
    }
    return cnt == 0;
}
bool checkValidString(string s)
{
    stack<int> st;
    stack<int> starStack;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (s[i] == '*')
        {
            starStack.push(i);
        }
        else
        {
            if (!st.empty())
            {
                st.pop();
            }
            else if (!starStack.empty())
            {
                starStack.pop();
            }
            else
            {
                return false;
            }
        }
    }

    while (!st.empty() && !starStack.empty())
    {
        if (st.top() > starStack.top())
        {
            return false;
        }
        st.pop();
        starStack.pop();
    }

    return st.empty();
}

;
bool checkStarString(string s, int cnt, int i)
{
    if (i == s.length())
        return cnt == 0;
    if (i == s.size())
        return false;
    if (s[i] == '(')
    {
        return checkStarString(s, cnt + 1, i + 1);
    }
    else if (s[i] == ')')
    {
        return checkStarString(s, cnt - 1, i + 1);
    }
    else if (s[i] == '*')
    {
        if (checkStarString(s, cnt, i + 1))
            return true;
        if (checkStarString(s, cnt, i + 1))
            return true;
        s[i] = '(';
        if (checkStarString(s, cnt + 1, i + 1))
            return true;
        s[i] = ')';
    }
    return false;
}
bool checkStarString2(string s)
{
    int minm = 0, maxm = 0;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            minm++;
            maxm++;
        }
        else if (s[i] == ')')
        {
            minm--;
            maxm--;
        }
        else if (s[i] == '*')
        {
            minm--;
            maxm++;
        }
        if (minm < 0)
            minm = 0; // more ) than (
        if (maxm < 0)
            return false;
    }
    return minm == 0;
}
int main()
{
    string s = "(*))";
    cout << checkStarString(s, 0, 0);
    cout << endl;
    cout << checkStarString2(s);

    return 0;
}