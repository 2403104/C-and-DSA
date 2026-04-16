#include <iostream>//directives (preprocessor) headers file
using namespace std;//
int main(){
    // std::cout<<"Ankit kumar";//without using namespace std
    // cout<<"Ankit kumar";//used to print 
    // cout<<"Ankit"<<endl<<"Kumar";//endl means end that line and print in the next line
    
    /*
    Variables naming convention
    lowercase
    UPPERCASE
    camelCase

    underscore and dollars allowed
    */
    // int n;
    // cin>>n;//used to take input from user
    // cout<<"Entered input is : "<<n;

    int a,b;
    cout<<"a: ";
    cin>>a;
    cout<<"b: ";
    cin>>b;
    int ans=a+b;
    cout<<"The sum of entered number is "<<ans;
    return 0;
}