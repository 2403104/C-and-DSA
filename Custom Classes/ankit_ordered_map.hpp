#pragma once
#include <iostream>
#include <utility>
#include <type_traits>
#include <string>
#include <iterator> 
using namespace std;
const bool RED=true;
const bool BLACK=false;
template<typename K, typename V>
struct Node{
    K key;
    V val;
    bool color;
    Node *left, *right, *parent;
    Node(K k, V v) key(k), val(v), left(NULL),right(NULL),parent(NULL);
};
template<typename K, typename V,typename Compare=less<K>>
class ankit_ordered_map{
    ankit_ordered_map<K, V>root;
    Compare cmp;
    void rotateLeft(Node<K,V>* &node){
        Node<K,V> *rightChild=node->right;
        node->right=rightChild->left;
        if(rightChild->left!=NULL){
            rightChild->left->parent=node;
        }
        if(!node->parent) root=rightChild;
        else if(node->parent->left==node) node->parent->left=rightChild;
        else node->parent->right=rightChild;
        rightChild->left=node;
        node->parent=rightChild;
    }
    void rotateRight(Node<K,V>* &node){
        Node<K,V> *leftChild=node->left;
        node->left=leftChild->right;
        if(leftChild->right!=NULL){
            leftChild->right->parent=NULL;
        }
        leftChild->parent=node->parent;
        if(!node->parent) root=leftChild;
        else if(node==node->parent->left) node->parent->left=leftChild;
        else node->parent->right=leftChild;
        leftChild->right=node;
        node->parent=leftChild;
    }
    void fixInsert(Node<K,V>* &node){
        Node<K,V>* parent=NULL;
        Node<K,V>* grandParent=NULL;
        while(node!=root && node->parent->color==RED){
            parent=node->parent;
            grandParent=parent->parent;
            if(parent==grandParent->left){
                Node<K,V>* uncle=grandParent->right;
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
                Node<K,V>* uncle=grandParent->left;
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
    Node<K,V>* bstInsert(Node<K,V>* root, Node<K,V>* newNode){
        Node<K,V>* curr=root;
        while(curr){
            if(cmp(curr->key,newNode->key)) curr=curr->right;
            else if(cmp(newNode->key,curr->key)) curr=curr->left;
            else{
                curr->val=newNode->val;
                delete newNode;
                return root;
            }
        }
        Node<K,V>* nr=NULL;
        
    }
public:
    ankit_ordered_map() : root(NULL) {} 
    void insert(const K&key, const V&value){
        Node<K,V>* newNode= new Node(key,value);
        Node<K,V>* root=bstInsert(root, newNode);
    }
};