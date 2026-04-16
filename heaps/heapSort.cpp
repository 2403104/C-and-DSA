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
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=NULL;
        right=NULL;
    }
};
Node* arrayToBT(vector<int> v){
    if(v.size()<1) return NULL;
    Node* root=new Node(v[0]);
    int i=1;
    queue<Node*> q;
    q.push(root);
    while(!q.empty() && i<v.size()){
        Node* front=q.front();
        q.pop();
        if(i<v.size()){
            front->left=new Node(v[i++]);
            q.push(front->left);
        }
        if(i<v.size()){
            front->right=new Node(v[i++]);
            q.push(front->right);
        }

    }
    return root;
}
void printLevelOrder(Node* root){
    if(!root) return ;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
    cout<<endl;
}
//Heapify is a process used to maintain the heap property for a node in a binary heaps.
void heapify(vector<int> &a, int n, int i){
    int maxIdx=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && a[l]>a[maxIdx])
        maxIdx=l;
    if(r<n && a[r]>a[maxIdx])
        maxIdx=r;

    if(maxIdx!=i){
        swap(a[i],a[maxIdx]);
        heapify(a,n,maxIdx);
    }
}

void heapSort(vector<int> &v){
    int n=v.size();
    for(int i=n/2-1;i>=0;i--){//leaf nodes(n/2 to n-1)
        heapify(v,n,i);
    }
    for(int i=n-1;i>0;i--){
        swap(v[0],v[i]);
        heapify(v,i,0);
    }
}

int main(){
    vector<int> v={5,1,2,7,8,9,6,4,3};
    Node* root=arrayToBT(v);
    int n=v.size();
    heapSort(v);
    for(auto i : v){
        cout<<i<<" ";
    }
    return 0;
}