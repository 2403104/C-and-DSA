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
priority_queue<int, vector<int>, greater<int>> minHeap;
priority_queue<int, vector<int>> maxHeap;

void insert(int x){
    if (minHeap.size()==maxHeap.size()){
        if(maxHeap.size()==0){
            maxHeap.push(x);
            return ;
        }
        if(x<maxHeap.top()) maxHeap.push(x);
        else minHeap.push(x);
    }else{
        if(maxHeap.size()>minHeap.size()){
            if(x>=maxHeap.top()) minHeap.push(x);
            else{
                
            }
        }
    }
}

int main(){
    insert(10);
    cout<<findMedian()<<endl;

    return 0;
}