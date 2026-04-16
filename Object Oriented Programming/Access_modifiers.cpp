# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Student{//student is a new data type
public://everything  below public are public
    string name;
    int rollNo;
    Student(string name, int rollNo, float marks){
        this->name=name;
        this->rollNo=rollNo;
        this->marks=marks;}

        void display(){
            cout<<this->name<<" "<<this->rollNo<<" "<<this->marks<<endl;}
        
        float getMarks(){//Getter
            return this->marks;
        }
        void setMarks(float m){//Setter
            this->marks=m;
        }

//if we want to print the class member and without changing that then we use Getter (just a name)
// and we can set the marks using setter
//getter ans seter are possible because we can use inside the class not outside the class 
//protected can be used in the derived class
private://everything below this are private 
    float marks;
    // void printInfo(){
    //     cout<<this->name<<" "<<this->rollNo<<" "<<this->marks<<endl;
    
};
int main(){
    Student s("Ankit kumar",2403104,76.5);//here no error for marks{but we can't change marks}
    // s.name="Ankit kumar";
    // s.rollNo=2403104;
    // s.marks=80;//will give error
    // s.printInfo();//will give error
    s.setMarks(80.5);
    cout<<s.getMarks()<<endl;
    s.display();

    return 0;
}