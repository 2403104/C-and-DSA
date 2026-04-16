#pragma once
#include <iostream>
#include <utility>
#include <type_traits>
#include <string>
#include <iterator> 
using namespace std;
namespace out {
    template <typename A, typename B>
    ostream& operator<<(ostream& cout, const pair<A, B>& p) {
        cout << "(" << p.first << ", " << p.second << ")";
        return cout;
    }
    template<
        typename Iterables,
        typename = decltype(begin(declval<Iterables>())),
        typename = typename enable_if<!is_same<Iterables, string>::value>::type
    >
    ostream& operator << (ostream &cout, const Iterables &container){
        bool space=false;
        cout<<endl;
        for(const auto &it : container){
            if(space) cout<<" ";
            cout<<it;
            space=true;
        }
        return cout;
    }
}
using namespace out;
const bool RED = true;
const bool BLACK = false;
template <typename T>
struct Node {
    T data;
    bool color;
    Node *left, *right, *parent;
    Node(const T& val) {
        data = val;
        parent = left = right = NULL;
        color = RED;
    }
};

template <typename T>
class ankit_unordered_set {
private:
    Node<T>* root;

    void rotateLeft(Node<T>* &node) {
        Node<T>* rightChild = node->right;
        node->right = rightChild->left;
        if (rightChild->left != NULL) {
            rightChild->left->parent = node;
        }
        rightChild->parent = node->parent;
        if (!node->parent) root = rightChild;
        else if (node == node->parent->left) node->parent->left = rightChild;
        else node->parent->right = rightChild;
        rightChild->left = node;
        node->parent = rightChild;
    }

    void rotateRight(Node<T>* &node) {
        Node<T>* leftChild = node->left;
        node->left = leftChild->right;
        if (leftChild->right != NULL) {
            leftChild->right->parent = node;
        }
        leftChild->parent = node->parent;
        if (!node->parent) root = leftChild;
        else if (node == node->parent->left) node->parent->left = leftChild;
        else node->parent->right = leftChild;
        leftChild->right = node;
        node->parent = leftChild;
    }

    void fixInsert(Node<T>* &node) {
        Node<T>* parent = NULL;
        Node<T>* grandParent = NULL;
        while (node != root && node->parent->color == RED) {
            parent = node->parent;
            grandParent = parent->parent;
            if (parent == grandParent->left) {
                Node<T>* uncle = grandParent->right;
                if (uncle && uncle->color == RED) {
                    grandParent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandParent;
                } else {
                    if (node == parent->right) {
                        rotateLeft(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    rotateRight(grandParent);
                    swap(parent->color, grandParent->color);
                    node = parent;
                }
            } else {
                Node<T>* uncle = grandParent->left;
                if (uncle && uncle->color == RED) {
                    grandParent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandParent;
                } else {
                    if (node == parent->left) {
                        rotateRight(parent);
                        node = parent;
                        parent = node->parent;
                    }
                    rotateLeft(grandParent);
                    swap(parent->color, grandParent->color);
                    node = parent;
                }
            }
        }
        root->color = BLACK;
    }
    void inorder(Node<T>* node) {
        if (!node) return;
        inorder(node->left);
        cout<<node->data<<' ';
        inorder(node->right);
    }

public:
    ankit_unordered_set() : root(NULL) {}

    void insert(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        Node<T>* parent = NULL;
        Node<T>* current = root;

        while (current) {
            parent = current;
            if (newNode->data < current->data) current = current->left;
            else if (current->data < newNode->data) current = current->right;
            else return;
        }

        newNode->parent = parent;
        if (!parent) root = newNode;
        else if (newNode->data < parent->data) parent->left = newNode;
        else parent->right = newNode;
        fixInsert(newNode);
    }
    void printTree() {
        inorder(root);
        cout << endl;
    }
};