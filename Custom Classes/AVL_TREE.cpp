#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value)
        : key(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* node) {
        if (!node) return 0;
        return node->height;
    }

    int getBalance(Node* node) {
        if (!node) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y -> left;
        Node* T2 = x -> right;

        x -> right = y;
        y -> left = T2;

        x -> height = max(getHeight(x -> left), getHeight(x -> right)) + 1;
        y -> height = max(getHeight(y -> left), getHeight(y -> right)) + 1;

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x -> right;
        Node* T2 = y -> left;

        y -> left = x;
        x -> right = T2;

        x -> height = max(getHeight(x -> left), getHeight(x -> right)) + 1 ;
        y -> height = max(getHeight(y -> left), getHeight(y -> right)) + 1 ;

        return y;
    }

    Node* insertNode(Node* node, int key) {
        if(!node){
            Node* newNode = new Node(key);
            newNode -> height = 1;
            return newNode;
        }
        if(node -> key < key){
            node -> right = insertNode(node -> right, key);
        }else if(node -> key > key){
            node -> left = insertNode(node -> left, key);
        }
        node -> height = 1 + max(getHeight(node -> left), getHeight(node->right));

        int bf = getBalance(node);
        //LL
        if(bf > 1 && key < node -> left -> key){
            return rightRotate(node);
        }

        //RR 
        if(bf < -1 && key > node -> right -> key){
            return leftRotate(node);
        }

        //LR
        

        //RL
    }

    Node* minValueNode(Node* node) {
        // find min
        Node* current = node;
        while (current && current->left)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* node, int key) {
        // delete
        return node;
    }

    void preOrder(Node* node) {
        if (node) {
            cout << node->key << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node* node) {
        if (node) {
            inOrder(node->left);
            cout << node->key << " ";
            inOrder(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key) {
        // call insert
        root = insertNode(root, key);
    }

    void remove(int key) {
        // call delete
        root = deleteNode(root, key);
    }

    void printPreOrder() {
        // print preorder
        preOrder(root);
        cout << endl;
    }

    void printInOrder() {
        // print inorder
        inOrder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);

    cout << "PreOrder: ";
    tree.printPreOrder();

    cout << "InOrder: ";
    tree.printInOrder();

    tree.remove(40);

    cout << "After Deletion:\n";
    tree.printPreOrder();
    tree.printInOrder();

    return 0;
}
