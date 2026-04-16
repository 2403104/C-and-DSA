#include<bits/stdc++.h>
using namespace std;
const bool RED=true;
const bool BLACK=false;
struct Node{
    int data;
    bool color;
    Node *left, *right, *parent;
    Node(int val){
        data=val;
        parent=left=right=NULL;
        color=RED;//new Nodes are red by default
    }
};
class RedBlackTree{ 
private:
    Node* root;
/*
        P                     
         \
          X(Node)
         / \
       T1    Y
            / \
          T2   T3

LEFT ROTATION

         P
        / \
           Y
          / \
         X   T3
        / \
      T1   T2

*/    
    void rotateLeft(Node* &node){
        Node* rightChild=node->right;
        node->right=rightChild->left;
        if(rightChild->left!=NULL){
            rightChild->left->parent=node;
        }
        rightChild->parent=node->parent;
        if(!node->parent) root=rightChild;
        else if(node==node->parent->left) node->parent->left=rightChild;
        else node->parent->right=rightChild;
        rightChild->left=node;
        node->parent=rightChild;
    }
/*
        P
        |
        Y(Node)
       / \
      X   T3
     / \
   T1   T2
ROTATE RIGHT
        P
        |
        X
       / \
     T1   Y
         / \
       T2   T3

*/    
    void rotateRight(Node* &node){
        Node* leftChild=node->left;
        node->left=leftChild->right;
        if(leftChild->right!=NULL){
            leftChild->right->parent=node;
        }
        leftChild->parent=node->parent;
        if(!node->parent) root=leftChild;
        else if(node==node->parent->left) node->parent->left=leftChild;
        else node->parent->right=leftChild;
        leftChild->right=node;
        node->parent=leftChild;
    }
    void fixInsert(Node* &node){
        Node* parent=NULL;
        Node* grandParent=NULL;
        while(node!=root && node->parent->color==RED){
            parent=node->parent;
            grandParent=parent->parent;
            if(parent==grandParent->left){
                Node* uncle=grandParent->right;
                if(uncle && uncle->color==RED){
                    grandParent->color=RED;
                    parent->color=BLACK;
                    uncle->color=BLACK;
                    node=grandParent;
                }else{
                    if(node==parent->right){
                        rotateLeft(parent);
                        node=parent;
                        parent=node->parent;
                    }
                    rotateRight(grandParent);
                    swap(parent->color,grandParent->color);
                    node=parent;
                }
            }else{
                Node* uncle=grandParent->left;
                if(uncle && uncle->color==RED){
                    grandParent->color=RED;
                    parent->color=BLACK;
                    uncle->color=BLACK;
                    node=grandParent;
                }else{
                    if(node==parent->left){
                        rotateRight(parent);
                        node=parent;
                        parent=node->parent;
                    }
                    rotateLeft(grandParent);
                    swap(parent->color,grandParent->color);
                    node=parent;
                }
            }
        }
        root->color=BLACK;
    }
public:
    RedBlackTree() : root(NULL) {}
    void insert(int data){
        Node* newNode= new Node(data);
        Node* parent=NULL;
        Node* current=root;
        while(current){
            parent=current;
            if(newNode->data<current->data) current=current->left;
            else current=current->right;
        }
        newNode->parent=parent;
        if(!parent) root=newNode;
        else if(newNode->data<parent->data) parent->left=newNode;
        else parent->right=newNode;
        fixInsert(newNode);
    }
    void inorder(Node* node){
        if(!node) return;
        inorder(node->left);
        cout<<node->data<<(node->color==RED?" (R) ":" (B) ");
        inorder(node->right);
    }
    void printTree(){
        inorder(root);
        cout<<endl;
    }
};
int main(){
    RedBlackTree rbt;
    rbt.insert(10);
    rbt.insert(20);
    rbt.insert(30);
    rbt.insert(15);
    rbt.insert(25);

    rbt.printTree();
    return 0;
}