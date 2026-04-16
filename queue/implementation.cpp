//ARRAY IMPLEMENTATION

//delete from front and add from last

// # include <iostream>
// using namespace std;
// #define n 20
// class queue{
//     int* arr;
//     int front;
//     int back;
// public:
//     queue(){
//         arr=new int[n];
//         front=-1;
//         back=-1;
//     }
//     void enqueue(int x){//add at LAST    
//         if (back==n-1){
//             cout<<"Stack overflow";
//             return ;
//         }
//         back++;
//         arr[back]=x;
//         if (front==-1) front++;
//     }
//     void dequeue(){//delete from front
//         if (front==-1|| front>back){
//             cout<<"Stack is empty";
//             return;
//         }
//         front++;
//     }
//     int peek(){//front element
//         if (front==-1 || front>back){
//             cout<<"Queue is empty"<<endl;
//             return -1;
//         }
//         return arr[front];
//     }
//     bool empty(){
//         if (front==-1 || front>back){
//             return true;
//         }    
//         return false;
//     }
// };
// int main(){
//     queue q;
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     q.enqueue(4);
//     q.enqueue(5);

//     while(!q.empty()){
//         cout<<q.peek()<<" ";
//         q.dequeue();
//     }
//     return 0;
// }


//LINKED LIST IMPLEMENTATION
//to save the memory 
/*
# include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node( int val){
        data=val;
        next=NULL;
    }
};
class queue{
    node* front;
    node* back;
    queue(){
        front=NULL;
        back=NULL;
    }
    void push(int x){
        node* n=new node(x);
        if (front==NULL){
            back=n;
            front=n;
            return;
        }
        back->next=n;
        back=n;
    }
    void pop(){
        if (front==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        node* todelete=front;
        front=front->next;
        delete todelete;
    }
    int peek(){
        if (front==NULL){
            cout<<"Queue is empty"<<endl;
            return;
        }
        return front->data;  
    }
    bool empty(){
        return front==NULL;
    }
};
int main(){

    return 0;
}
*/

