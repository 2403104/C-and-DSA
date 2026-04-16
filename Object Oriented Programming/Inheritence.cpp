# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

class Scooty{
public:
    int topSpeed;
    float mileage;
private:
    int bootSpace;
};
class Bike : public Scooty{//: stands for scooty
public:
    int gear;
};
/*
FOR MULTIPLE INHERITENCE
class Name: public class1,class2 //Name will inherit all the public from class1, and class2
*/
int main(){
    Bike b;
    b.gear=6;
    b.mileage=12.5;
    b.topSpeed=180;
    // b.bootSpace=500;//can't be accessed
    return 0;
}