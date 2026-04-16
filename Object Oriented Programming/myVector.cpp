# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
//user defined data structure
class Vector{
public:
    int size;
    int capacity;
    int* arr;

    Vector(){
        size=0;
        capacity=1;
        arr=new int[1];//we added the address of one int in thr arr pointer
    }
    void add(int el){
     if (size==capacity)   {
        capacity*=2;
        int* arr2=new int[capacity];
        for (int i=0;i<size;i++){
            arr2[i]=arr[i];
        }
        arr=arr2;
     }
     arr[size]=el;
     size++;
    }
    void printArray(){
        for (int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    int get(int idx){
        if (idx>=size || idx<0){ 
            cout<<"Invalid index";
            return -1;
        }
        else{
        return arr[idx];}
    }
    void remove(){
        if (size==0) cout<<"Array is empty";
        size--;
    }
};

int main(){

Vector v;
v.add(10);
v.add(20);
v.add(84);
v.remove();
v.add(12);
v.printArray();
v.get(5);
    return 0;
}