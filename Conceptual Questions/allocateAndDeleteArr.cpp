#include <bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int val;
    Node(int t = 0) : val(t) {
        cout << "Constructing Node with val = " << val << endl;
    }
    ~Node() {
        cout << "Destructing Node with val = " << val << endl;
    }
};
int main()
{
    int n=10;
    //Allocate raw memory for n Node Objects
    Node* arr=(Node*) operator new[](n*sizeof(Node));
    size_t i;
    for(i=0;i<n;i++) new (&arr[i]) Node(i);//placement new (syntax : new address type(args))

    for (i = 0; i < n; i++) {
        cout << "arr[" << i << "] = " << arr[i].val << endl;
    }

    for(i=0;i<n;i++){
        arr[i].~Node();//manual destructor call
    }
    operator delete[](arr);//free the raw memory

    return 0;
}