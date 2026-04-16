# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
/*
new :
memory is allocated at the runtime not at the compile time
useful when we don't know the size of the memory in advance
new returns a pointer to the allocated memory. 
This pointer is used to access or modify the allocated memory.
*/
//pass by reference
// void change(int* a){//storing the address to the provide pointer
//     *a=10;
//     return ;
// }

//pass by reference using allias
// void change(int &b){//we will pass the original value in the function
//     b=20;
//     return ;
// }

void reverseArray(int* arr, int size) {
    int* start = arr;             // Pointer to the first element
    int* end = arr + size - 1;    // Pointer to the last element

    while (start < end) {          // Loop until pointers meet or cross
        int temp = *start;         // Swap the values
        *start = *end;
        *end = temp;

        start++;                   // Move start forward
        end--;                     // Move end backward
    }
}
int main(){
//pointer : special variables that stores the address of other variables

// int n=24;
// int* ptr=&n;
// int** ptr1= &ptr;
// cout<<ptr1<<endl;
// cout<<ptr<<endl; 
// cout<<&n<<endl;//address of that n
// cout<<*(ptr);//dereferencing 

//NULL POINTER
// int* ptr;//gives the garbage value 
// int* ptr=NULL;
// cout<<ptr;//we can't dereference 

// int a=34;
// change(&a);//passing the address of a
// change(a);//passing directly the value(function will take the copy of that address)
// cout<<a<<endl;

//array pointers
// int arr[]={1,2,4,5,7,8,9};//arr is a type of pointer(constant pointer which can't be changed through out)(it always points the first element  )
//cout<<arr<<endl;//print the address of the arr[]
// cout<<*arr<<endl;
// cout<<*(arr+1)<<endl;//give the address   


// int a=4,b=6;
// int* ptr=&a;
// ptr=&b;//now pointer will change its address from a to b
// cout<<*ptr;//storing the other values   

// int a=56;
// int* ptr=&a;
// cout<<ptr<<endl;
// ptr++;//adding one int means four bytes (similarlyy for two and three )
// cout<<ptr<<endl;//now we are going to get the garbage value

//pointer arithmetic(-,<=,=,>,>=,==,!=)  applicable except +3

//NEW
int* ptr = new int;  // Allocates memory for one integer and returns its address to 'ptr'
*ptr = 42;           // Assigns the value 42 to the allocated memory
cout<<*ptr;

double* dptr = new double;  // Allocates memory for a double
*dptr = 3.14;               // Assigns a value to the allocated memory

int* arr = new int[5];  // Allocates memory for an array of 5 integers
arr[0] = 10;            // Access and modify elements using array indexing

struct node {
    int data;
    node* next;
    node(int val) : data(val), next(nullptr) {}  // Constructor
};

node* n = new node(5);  // Allocates memory for a 'node' object and initializes it with value 5

int* ptr = new int(10);  // Allocate memory for a integer whose value is mentioned as 10
delete ptr;              // Free memory allocated for a single variable

int* arr = new int[5];   // Allocate an array of 5 integers
delete[] arr;            // Free the allocated array

    return 0;
}