#include <bits/stdc++.h>
using namespace std;
class BankAccount
{
    float balance;

public:
    BankAccount()
    {
        this->balance = 0;
        cout << "BA ctor called" << endl;
    }
    void deposit(float amt)
    {
        balance += amt;
    }
    void withdraw(float amt)
    {
        if (balance >= amt)
        {
            balance -= amt;
        }
    }
    float getBalance()
    {
        return balance;
    }
};
class SavingAccount : public BankAccount
{
    static const float minBal;
    float rate;

public:
    SavingAccount(float rate)
    {
        cout << "SA ctor called" << endl;
        this->rate = rate;
    }
    void addIntarest()
    {
        deposit(getBalance() * rate);
    }
    void withdraw(float amt)
    {
        if (getBalance() - amt >= this->minBal)
            BankAccount::withdraw(amt);
    }
};
class B
{
    public:
    B() { cout << "B ctor" << endl; }
    ~B() { cout << "B dtor" << endl; }
};

class D : public B
{
    public:
    D() { cout << "D ctor" << endl; }
    ~D() { cout << "D dtor" << endl; }
};
const float SavingAccount::minBal = 500.00;

class X{
    private: int x;
    protected : int y;
    public : int z;
    X(){
        x=1;
        y=2;
        z=3;
    }
};
class Y : public X{
    public:
    Y(){
        cout<<"y "<<y<<endl;
    }
};
//Assignment Compatibility in C++ refers to the ability of one object to be assigned 
//to another, based on the type of the variables involved. It defines whether one type 
//can be assigned to another type either implicitly or explicitly.
int main()
{
    // D d;//will call ctor in top to bottom and dctor in bottom to top
    Y y ;
    
    return 0;
}