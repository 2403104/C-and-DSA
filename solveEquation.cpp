#include <bits/stdc++.h>
using namespace std;

pair<int, int> count(string s)
{
    int xCnt = 0, val = 0;
    int n = s.length();
    char sign = '+';
    int curr = 0;
    bool isX = false;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '+' || s[i] == '-')
        {
            if (isX)
            {
                if (curr != 0)
                {
                    xCnt += (sign == '+') ? curr : -curr;
                }
            }
            else
            {
                val += (sign == '+') ? curr : -curr;
            }
            curr = 0;
            isX = false;
            sign = s[i];
        }
        else if (isdigit(s[i]))
        {
            curr = curr * 10 + (s[i] - '0');
        }
        else if (s[i] == 'x')
        {
            isX = true;
            if (curr == 0 &&
                (i == 0 || s[i - 1] == '+' || s[i - 1] == '-'))
            {
                curr = 1;
            }
        }
    }

    if (isX)
    {
        if (curr != 0)
        {
            xCnt += (sign == '+') ? curr : -curr;
        }
    }
    else
    {
        val += (sign == '+') ? curr : -curr;
    }

    return {xCnt, val};
}
string solveEquation(string eq)
{
    string equation = "";
    int n = eq.size();
    int equal;
    for (int i = 0; i < n; i++)
    {
        char ch = eq[i];
        if (ch != ' ')
            equation += ch;
    }
    for (equal = 0; equal < n; equal++)
    {
        if (equation[equal] == '=')
            break;
    }
    string left = equation.substr(0, equal);
    string right = equation.substr(equal + 1);
    int leftXcnt = 0, rightXcnt = 0, leftVal = 0, rightVal = 0;
    pair<int, int> leftSolve = count(left);
    pair<int, int> rightSolve = count(right);
    leftXcnt = leftSolve.first;
    rightXcnt = rightSolve.first;
    leftVal = leftSolve.second;
    rightVal = rightSolve.second;
    if (rightVal == leftVal && leftXcnt == rightXcnt)
        return "Infinite solutions";
    if (leftXcnt == rightXcnt)
        return "No solution";
    float r = float(rightVal - leftVal) / (leftXcnt - rightXcnt);
    string res = "x=" + to_string(r);
    return res;
}

int main()
{
    string s;
    cin >> s;
    cout << solveEquation(s);

    return 0;
}