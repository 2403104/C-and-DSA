#include <bits/stdc++.h>
using namespace std;

vector<int> nume(string s)
{
    vector<int> num;
    char sign = '+';
    int curr = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            curr = curr * 10 + (s[i] - '0');
        }
        else if (s[i] == '/')
        {
            (sign == '+') ? num.push_back(curr) : num.push_back(-curr);
            curr = 0;
        }
        else if (s[i] == '+' || s[i] == '-')
        {
            sign = s[i];
            curr = 0;
        }
    }
    return num;
}
vector<int> deno(string s)
{
    int curr = 0;
    char sign = '+';
    vector<int> deno;
    for (int i = 0; i < s.length(); i++)
    {
        if (isdigit(s[i]))
        {
            curr = curr * 10 + (s[i] - '0');
        }
        else if (s[i] == '/')
            curr = 0;
        else if (s[i] == '+' || s[i] == '-')
        {
            if (i != 0)
            {
                deno.push_back(curr);
            }
            curr = 0;
        }
    }
    deno.push_back(curr);
    return deno;
}
int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

int lcmOfArray(vector<int> &nums)
{
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        result = lcm(result, nums[i]);
    }
    return result;
}
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
string fractionAddition(string expression)
{
    vector<int> n = nume(expression);
    vector<int> d = deno(expression);
    int lcm = lcmOfArray(d);
    int ans = 0;
    int size = n.size();
    for (int i = 0; i < size; i++)
    {
        int div = lcm / d[i];
        ans += n[i] * div;
    }
    cout << endl;
    if (ans == 0)
        return "0/1";
    int hcf = gcd(abs(ans), abs(lcm));
    string res = to_string(ans / hcf) + "/" + to_string(lcm / hcf);
    return res;
}

int main()
{
    string s;
    cin>>s;
    cout<<fractionAddition(s);
    return 0;
}