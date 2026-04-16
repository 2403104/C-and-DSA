//QUEUE USING STACK
// # include <iostream>
// # include <stack>
// using namespace std;
// class queue{
//     stack<int>st1;
//     stack<int>st2;
// public:
//     void push(int x){
//         st1.push(x);
//     }
//     int pop(){
//         if (st1.empty() && st2.empty()){
//             cout<<"Stack is empty"<<endl;
//             return- 1;
//         }
//         if (st2.empty()){
//             while(!st1.empty()){
//                 st2.push(st1.top());
//                 st1.pop();
//             }
//         }
//         int topVal=st2.top();
//         st2.pop();
//         return topVal;
//     }
//     bool empty(){
//         if (st1.empty() && st2.empty()){
//             return true;
//         }
//         return false;
//     }
// };
// int main(){

//     queue q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);

//     cout<<q.pop();
//     return 0;
// }

// # include <iostream>
// # include <stack>
// using namespace std;
// class queue{
//     stack<int>st1;
// public:
//     void push(int x){
//         st1.push(x);
//     }
//     int pop(){
//         if (st1.empty()){
//             cout<<"Queue is empty";
//             return -1;
//         }
//         int x=st1.top();
//         st1.pop();
//         if (st1.empty()){
//             return x;
//         }
//         int item=pop();
//         st1.push(x);
//         return item;

//     }
//     bool empty(){
//         if (st1.empty()){
//             return true;
//         }
//         return false;
//     }
// };
// int main(){

//     queue q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);

//     cout<<q.pop()<<" ";
//     q.push(45);
//     cout<<q.pop()<<" ";
//     cout<<q.pop()<<" ";
//     return 0;
// }
