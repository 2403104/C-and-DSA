#include<bits/stdc++.h>
using namespace std;
void test() throw(int , char, runtime_error){//need to mention the type of error to sent the error
    throw runtime_error("runtime_error");
}
int main(){

    try{
        test();
    }catch(int e){
        cout<<"INT_TYPE_ERROR "<<e<<endl;
    }catch(char e){
        cout<<"CHAR_TYPE_ERROR "<<e<<endl;
    }catch(runtime_error err){
        cout<<"RUNTIME_ERROR "<<err.what()<<endl;
    }

    return 0;
}