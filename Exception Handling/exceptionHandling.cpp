#include <bits/stdc++.h>
#include <exception>
#include <stdexcept>
using namespace std;
// int main(){
//     int a,b;
//     cin>>a>>b;
//     try{
//         if(b==0){
//             throw "Divide by zero error";
//         }
//         int c=a/b;
//         cout<<c<<endl;
//     }catch(const char *e){
//         cout<<"Excetion occured"<<endl<<e;
//     }
//     return 0;
// }

// int main(){
//     int a,b;
//     cin>>a>>b;
//     try{
//         if(b==0) throw runtime_error("Division by zero is not possible");
//         int c=a/b;
//         cout<<c<<endl;
//     }catch(runtime_error &error){
//         cout<<"Exception Occured"<<endl;
//         cout<<error.what();
//     }

//     return 0;
// }

// int main(){
//     try{
//         throw runtime_error("runtime_error");
//     }catch(const char *err){
//         cout<<err<<endl;
//     }catch(int err){
//         cout<<err<<endl;
//     }catch(runtime_error err){
//         cout<<err.what()<<endl;
//     }


//     return 0;
// }
int main(){

    // try{
    //     throw runtime_error("runtime_error");
    // }catch(...){//handle all type of error
    //     cout<<"Some exception occured!!"<<endl;
    // }


    try{
        throw runtime_error("runtime_error");
    }catch(runtime_error err){
        cout<<err.what()<<endl;
    }catch(...){//handle all type of error
        cout<<"Some exception occured!!"<<endl;
    }

    return 0;
}