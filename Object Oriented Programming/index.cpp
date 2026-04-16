# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Student{//student is a new data type
public:
    string name;
    int rollNo;
    float cpi;

    //constructor

    //if no constructor is used then default constructor is called
    //default constructor
    Student(){
    //we can use like this
    /*
    Student a(){//if you won't give any data then we get garbage value
    }
    a.name =name
    a.age=age
    */
    }

    //parametrized constructor
    Student(string n, int r, float c){//first parameter get stored in n, r, c
        // name =n ;
        // rollNo=r;
        // cpi=c;
        this->name=n;
        this->rollNo=r;
        this->cpi=c;
    }
    //we can create multiple constructor
    Student(string n, int r){//first parameter get stored in n, r, c
        name =n ;
        rollNo=r;
    }
    void printInfo(){
        cout<<this->name<<" "<<this->rollNo<<" "<<this->cpi<<" ";
    }
};

void print_detail(Student s){
    cout<<s.name<<" "<<s.rollNo<<" "<<s.cpi<<endl;
}
//pass by value 
// void change(Student s){
//     s.cpi+=0.8;
// }

// pass by reference
// void change(Student& s){
//     s.cpi+=0.8;
// }
void change(Student* s){
    // (*s).cpi+=0.8;
    s->cpi+=0.8;//both are same
}


int main(){
//s1 and s2 are the instance of the class and called as object
    // Student s1;
    // s1.name="Ankit kumar";
    // s1.cpi=8.5;
    // s1.rollNo=2403104;

    // print_detail(s1);
    // change(s1);
    // print_detail(s1);

//with constructor 
// s.cpi=8.8;//it will be overwritten
// Student s1("Ankit kumar",2403104,8.5);//order should not change
// Student s2("Sarang Dhanwade",2403101,8.2);

// Student a("Ankit kumar",2403104);
// a.cpi=8.4;

// Student s2=s1;// we can copy{ it is going to be Deep copy}
// s2.name="Sarang";

// Student s3(s1);//copy constructor{ Deep copy}

// print_detail(s1);
// s1.printInfo();

// Student* ptr=&s1;
// ptr->cpi=8.6;
// (*ptr).cpi=8.6;
// change(&s1);
// s1.printInfo();
// cout<<(*ptr).name;

// Student* s2=new Student("Sarang Dhanwade",2403101,8.2);//most useful 
// cout<<s2->name;



    return 0;
}