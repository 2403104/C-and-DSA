# include <iostream>
# include <set>
# include <unordered_set>
using namespace std;

int main(){
//ORDERED SET
/*
contains unique element 
implement using bst
element are in sorted order
random access is not possible
*/
// set<int>s ;//will print in ascending order
// set<int,greater<int>>s ;//will be printed in descending order
// s.insert(4);
// s.insert(8);
// s.insert(1);
// s.insert(9);
// s.insert(3);
// s.insert(5);
// s.insert(1);//as it id duplicate so it will not be in set
// s.insert(1);//as it id duplicate so it will not be in set
// for (auto i:s){
//     cout<<i<<" ";
// }

// for (auto i=s.begin();i!=s.end();i++){
//     cout<<*i<<" ";
// }

// for (auto i=s.rbegin();i!=s.rend();i++){//rbegin return an iterator from end 
//     cout<<*i<<" ";
// }

// cout<<*s.upper_bound(9);//if it is the last element then it returns the upper_bound as last element
// cout<<*s.lower_bound(1);
// cout<<(s.upper_bound(9)==s.end());

// s.erase(3);//erase that particular element
// s.erase(s.begin());//delete the element by using the pointer of the element
// cout<<s.size();

// for (auto i : s){
//     cout<<i<<" ";
// }


//MULTISET 
// multiset <int> s;//duplicates are allowed
// s.insert(5);
// s.insert(4);
// s.insert(5);
// s.insert(2);
// s.insert(9);
// s.insert(5);
// s.insert(6);

// s.erase(5);//will delete all the occurence of 5
// s.erase(s.begin());//will delete only the first element even it has occurence
// s.erase(s.find(5));//will erase the particular pointer element
// for (auto i : s){
//     cout<<i<<" ";
// }

unordered_set<int> s;//won't be in sorted order and duplicate is  not allowed

s.insert(5);
s.insert(4);
s.insert(6);
s.insert(2);
s.insert(5);
s.insert(2);
s.insert(9);
s.insert(9);
s.insert(0);

for (auto i : s){
    cout<<i<<" ";
}

    return 0;
}