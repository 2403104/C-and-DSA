#include<bits/stdc++.h>
using namespace std;
int main(){
    try{
        // throw runtime_error("rutime_error_outside_inner_tryc");//outer catch block will catch this
        try{
            throw "A character type error";
        }catch(const char *err){
            cout<<"CHAR_TYPE_ERR(INNER_BLOCK) "<<err<<endl;
            // throw;//same error will be re-thrown to the outer block also
            throw runtime_error("runtime_error");//will throw only runtime error to the outer block
        }

    }catch(const char *err){
        cout<<"CHAR_TYPE_ERR(OUTER_BLOCK) "<<err<<endl;
    }catch(runtime_error err){
        cout<<"RUNTIME_ERR(OUTER_BKOCK) "<<err.what()<<endl;
    }catch(...){
        cout<<"UNEXPECTED_ERR(OUTER_BLOCK) "<<endl;
    }

    return 0;
}