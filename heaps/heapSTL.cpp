# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;

#define vi vector<int>;
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for (int i=a;i<b;i++)
#define ff first
#define ss second

//max heap priority_queue<int, vector<int>>//maxm at the top
//min heap priority_queue<int, vector<int> , greater<int>>

//we have only max heap in stl to reverse that we use greater<int> to reverse the max heap into the min heap

/*
priority_queue<T, Container, Compare>
T=data type of element strored int the container
container=holds the element with the the data type same to t

*/
int main(){
    priority_queue<int,vector<int>>maxHeap;
    maxHeap.push(2);
    maxHeap.push(3);
    maxHeap.push(7);
    maxHeap.push(9);
    maxHeap.push(5);
    maxHeap.push(6);
    maxHeap.push(0);

    // cout<<maxHeap.top()<<endl;
    // maxHeap.pop();

    priority_queue<int, vector<int> , greater<int>>minHeap;
    minHeap.push(2);
    minHeap.push(3);
    minHeap.push(7);
    minHeap.push(9);
    minHeap.push(5);
    minHeap.push(6);
    minHeap.push(0);

    // cout<<minHeap.top()<<" ";
    // minHeap.pop();

    /*
    COMPLEXITY 
    push,pop =O(log (n))
    top, size=O(1);
    */

    return 0;
}
// Demonstrating some inbuilt functions of heap in STL

// Creating a vector
// vector<int> v = {10, 20, 30, 5, 15};

// // Converting vector into a heap
// make_heap(v.begin(), v.end());
// cout << "The maximum element of heap is : " << v.front() << endl;

// // Adding an element to the heap
// v.push_back(99);
// push_heap(v.begin(), v.end());
// cout << "The maximum element of heap after push is : " << v.front() << endl;

// // Removing the maximum element from the heap
// pop_heap(v.begin(), v.end());
// v.pop_back();
// cout << "The maximum element of heap after pop is : " << v.front() << endl;

// // Sorting the heap
// sort_heap(v.begin(), v.end());
// cout << "Heap after sorting : ";
// for (int i : v) cout << i << " ";
// cout << endl;