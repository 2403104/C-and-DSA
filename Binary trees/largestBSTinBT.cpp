#include <iostream>
#include <climits>
using namespace std;
struct Node{
    int data;
    Node *left,*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};
Info largestBSTinBT(Node* root){
    if(!root) {
        return {0,INT16_MIN,INT16_MAX,0,true};
    }
    if(root->left==NULL && root->right==NULL){
        return {1,root->data,root->data,1,true};
    }
    Info leftInfo=largestBSTinBT(root->left);
    Info rightInfo=largestBSTinBT(root->right);

    Info curr;
    curr.size=1+leftInfo.size+rightInfo.size;
    
    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max<root->data && rightInfo.min>root->data){
        curr.min=min(min(leftInfo.min,rightInfo.min),root->data);
        curr.max=max(max(leftInfo.max,rightInfo.max),root->data);
        curr.ans=curr.size;
        curr.isBST=true;
        return curr;
    }
    curr.ans=max(leftInfo.ans,rightInfo.ans);
    curr.isBST=false;
    return curr;
}
Node* createSampleTree() {
    Node* root = new Node(4);
    root->left = new Node(8);
    root->right = new Node(9);
    root->left->left = new Node(6);
    root->left->right = new Node(1);
    root->left->left->left = new Node(4);
    root->right->left = new Node(-5);
    root->right->left->right = new Node(10);
    return root;
}

int main(){
    Node* root=createSampleTree();
    // Info res=largestBSTinBT(root);
    // Node* root=new Node(15);
    // root->left=new Node(20);
    // root->right=new Node(30);
    // root->left->left=new Node(5);

    Info ans=largestBSTinBT(root);
    cout<<ans.ans;

    return 0;
}