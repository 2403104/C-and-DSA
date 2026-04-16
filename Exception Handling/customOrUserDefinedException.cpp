#include<bits/stdc++.h>
#include<exception>
using namespace std;
class OverSpeed : public exception{
    int speed;
public:
    const char* what(){
        return "Check out your car speed.\nYou are in the car not in the aeroplane";
    }
    void getSpeed(){
        cout<<"Your car speed is "<<speed<<endl;
    }
    void setSpeed(int speed){
        this->speed=speed;
    }
};
class Car{
    int speed;
public:
    Car(){
        speed=0;
        cout<<"Speed is 0."<<endl;
    }
    void accelarate(){
        for(;;){
            speed+=10;
            cout<<"Speed is "<<speed<<endl;
            if(speed>=250){
                OverSpeed s;
                s.setSpeed(speed);
                throw s;
            }
        }
    }
};
int main(){

    Car car;
    try{
        car.accelarate();
    }catch(OverSpeed s){
        cout<<s.what()<<endl;
        s.getSpeed();
    }
    
    return 0;
}