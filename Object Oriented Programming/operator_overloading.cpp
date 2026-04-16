# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
class Fraction{
public:
    int num;
    int den;
    Fraction(int num, int den){
        this->num=num;
        this->den=den;
    }
    void display(){
        cout<<this->num<<"/"<<this->den<<endl;
    }
    Fraction add(Fraction f){
        int newNum=this->num*f.den+this->den*f.num;
        int newDen=this->den*f.den;
        Fraction ans(newNum,newDen);
        return ans;

    }
    Fraction operator +(Fraction f){
        int newNum=this->num*f.den+this->den*f.num;
        int newDen=this->den*f.den;
        Fraction ans(newNum,newDen);
        return ans;

    }
};

int main(){

Fraction f1(5,6);
Fraction f2(7,8);
f1.display();
f2.display();

// Fraction f3=f1.add(f2);
Fraction f3=f2+f1;
f3.display();


    return 0;
}