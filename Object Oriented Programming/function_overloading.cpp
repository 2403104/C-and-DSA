#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class A
{
public:
    // function overloading
    void sum(int a, int b)
    {
        cout << a + b << endl;
    }
    void sum(int a, int b, int c)
    {
        cout << a + b + c << endl;
    }
    void sum(string a, string b)
    {
        cout << a + " " + b << endl;
    }
};

int main()
{
    A a;

    return 0;
}