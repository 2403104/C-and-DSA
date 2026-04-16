/*
push and pop from end 
insert and delete from end
Header file<deque>
*/
# include <iostream>
# include <deque>
using namespace std;
int main(){

deque<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_front(3);
    d.push_front(4);
    d.pop_back();
    d.pop_front();

    for (auto i: d){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<d.size()<<endl;

    return 0;
}