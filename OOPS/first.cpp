#include<bits/stdc++.h>
using namespace std;
class Foo {
    int* p;
public:
    Foo(int x) {
        cout << "Contructor Called! " << endl;
        p = new int(x); 
    }
    Foo(const Foo & other){
        p = new int(*other.p);
        cout << "Copy Contructor Called! " << endl;
    }
    ~Foo() {
        cout << "Destructor Called! " << endl;
        delete p; 
    }
};
int main(){
    Foo a(1);
    Foo b(2);
    
    


    return 0;
}