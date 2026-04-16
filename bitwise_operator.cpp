#include <iostream>
using namespace std;
int main(){
    //&,|,^,<<,>>{BITWISE OPERATOR}
    // int a=4;
    // int b=8;
    // cout<<(4&8);//convert both number to binary and then take corresponding and
    // cout<<(a|b);
    // cout<<(a^b);//(different gives 1 and same gives 0)
    // cout<<(a<<1);//each will shift left by 1 (ans is number multiplied by 2**shift)
    // cout<<(a>>1);(number will be divided by 2**shift)

    //SCOPE
    //DATA TYPES MODIFIER(change the meaninig of the existing data types)
    cout<<sizeof(int)<<endl;//4
    cout<<sizeof(long long int)<<endl;//8
    cout<<sizeof(short int)<<endl;//2
    unsigned int x=45;
    cout<<x<<endl;//remove msb and size increases by 2

    return 0;
}