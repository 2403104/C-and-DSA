#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, sum = 0;
    x = 1;
    y = 2;
    int iarr[50];
    for (int i = 0; i < 20; i++)
    {
        iarr[i] = sum += x * y;
#ifdef DEBUG
        printf("iarr[i]=%d, x=%d, y=%d \n", iarr[i+100], x, y);
#endif
        x += 5;
        y += 2;
    }
    printf("Sum = %d \n", sum);
    return 0;
}