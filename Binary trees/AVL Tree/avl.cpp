// #include <bits/stdc++.h>
// using namespace std;

// struct Node {
//     int key;
//     Node* left;
//     Node* right;
//     int height;

//     Node(int val) : key(val), left(NULL), right(NULL), height(1) {}
// };

// int height(Node* node){
//     if(!node) return 0;
//     return node ->height;
// };
// int getBalance(Node* node){
//     if(!node) return 0;
//     return height(node -> left) - height(node -> right);
// };


// Node* rightRotate(Node* x){
//     Node* y = x -> left;
//     Node* T1 = y -> right;

//     y -> right = x;
//     x -> left = T1;

//     x -> height = 1 + max(height(x -> left), height(x -> right));
//     y -> height = 1 + max(height(y -> left), height(y -> right));

//     return y;

// };
// Node* leftRotate(Node* x){
//     Node* y = x -> right;
//     Node* T1 = y -> left;

//     y -> left = x;
//     x -> right = T1;

//     x -> height = 1 + max(height(x -> left), height(x -> right));
//     y -> height = 1 + max(height(y -> left), height(y -> right));

//     return y;
// };

// Node* insert(Node* node, int key){
//     if (node == nullptr)
//         return new Node(key);

//     if (key < node->key){
//         node->left = insert(node->left, key);}
//     else if (key > node->key){
//         node->right = insert(node->right, key);}
//     else{
//         return node; }
    
//     node -> height = 1 + max(height(node -> left), height(node -> right));

//     int balance = getBalance(node);

//     if(balance > 1 && key < node -> left -> key){
//         return rightRotate(node);
//     }
//     if(balance > 1 && key > node -> left -> key){
//         node -> left = leftRotate(node -> left);
//         return rightRotate(node);
//     }
//     if(balance < -1 && key > node -> right -> key){
//         return leftRotate(node);
//     }
//     if(balance < -1 && key < node -> right -> key){
//         node -> right = rightRotate(node -> right);
//         return leftRotate(node);
//     }
    
//     return node;
// };
// Node* minValueNode(Node* node){
//     Node* curr = node;
//     while(curr && curr -> right){
//         curr = curr -> right;
//     }
//     return curr;
// };
// Node* deleteNode(Node* root, int key){
//     if(!root) return root;
//     if(key < root -> key){
//         root -> left = deleteNode(root -> left, key);
//     }else if(key > root -> key){
//         root -> right = deleteNode(root -> right, key);
//     }else{
//         if(!root -> left){
//             Node* right = root -> right;
//             delete root;
//             return right;
//         }else if(!root -> right){
//             Node* left = root -> left;
//             delete root;
//             return left;
//         }else{
//             Node* temp = minValueNode(root -> left);
//             root -> key = temp -> key;
//             root -> left = deleteNode(root -> left, temp -> key);
//         }
//     }
//     if(!root) return NULL;
//     root -> height = 1 + max(height(root -> left), height(root -> right));
//     int balance = getBalance(root);
    
//     if(balance > 1 && getBalance(root -> left) >= 0){
//         return rightRotate(root);
//     }
//     if(balance > 1 && getBalance(root -> left) < 0){
//         root -> left = leftRotate(root ->left);
//         return rightRotate(root);
//     }
//     if (balance < -1 && getBalance(root->right) <= 0)
//         return leftRotate(root);

//     if (balance < -1 && getBalance(root->right) > 0) {
//         root->right = rightRotate(root->right);
//         return leftRotate(root);
//     }
//     return root;
// };
// Node* search(Node* root, int key){
//     if(!root) return NULL;
//     if(key < root -> key) return search(root -> left, key);
//     else if(key > root -> key) return search(root -> right, key);
//     return root;
// };

// void inorder(Node* root) {
//     if (root) {
//         inorder(root->left);
//         cout << root->key << " ";
//         inorder(root->right);
//     }
// }

// void preorder(Node* root) {
//     if (root) {
//         cout << root->key << " ";
//         preorder(root->left);
//         preorder(root->right);
//     }
// }

// void postorder(Node* root) {
//     if (root) {
//         postorder(root->left);
//         postorder(root->right);
//         cout << root->key << " ";
//     }
// }


// int main() {
//     Node* root = nullptr;

//     // --- INSERT TESTS ---
//     root = insert(root, 10);
//     root = insert(root, 20);
//     root = insert(root, 30);
//     root = insert(root, 40);
//     root = insert(root, 50);
//     root = insert(root, 25);
//     root = insert(root, 49);

//     cout << "Inorder traversal after insertions: ";
//     inorder(root);
//     cout << endl;

//     // --- SEARCH TEST ---
//     int keyToSearch = 25;
//     Node* found = search(root, keyToSearch);
//     if (found)
//         cout << "Key " << keyToSearch << " found in the tree.\n";
//     else
//         cout << "Key " << keyToSearch << " not found.\n";

//     // --- DELETE TEST ---
//     root = deleteNode(root, 40);
//     cout << "Inorder traversal after deleting 40: ";
//     inorder(root);
//     cout << endl;

//     // --- ADDITIONAL TRAVERSAL TESTS ---
//     cout << "Preorder traversal: ";
//     preorder(root);
//     cout << endl;

//     cout << "Postorder traversal: ";
//     postorder(root);
//     cout << endl;

//     return 0;
// }









#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    int height(Node* node) {
        if (!node) return 0;
        return node->height;
    }

    int getBalance(Node* node) {
        if (!node) return 0;
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* x) {
        Node* y = x->left;
        Node* T1 = y->right;
        y->right = x;
        x->left = T1;
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T1 = y->left;
        y->left = x;
        x->right = T1;
        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));
        return y;
    }

    Node* insert(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;
        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    Node* minValueNode(Node* node) {
        Node* curr = node;
        while (curr && curr->left)
            curr = curr->left;
        return curr;
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) return root;
        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left) {
                Node* right = root->right;
                delete root;
                return right;
            } else if (!root->right) {
                Node* left = root->left;
                delete root;
                return left;
            } else {
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }
        if (!root) return nullptr;
        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getBalance(root);
        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        return root;
    }

    void deleteKey(int key) {
        root = deleteNode(root, key);
    }

    Node* search(Node* node, int key) {
        if (!node) return nullptr;
        if (key < node->key) return search(node->left, key);
        else if (key > node->key) return search(node->right, key);
        return node;
    }

    Node* search(int key) {
        return search(root, key);
    }

    void inorder(Node* node) {
        if (node) {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }
    }

    void preorder(Node* node) {
        if (node) {
            cout << node->key << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->key << " ";
        }
    }

    void inorder() { inorder(root); }
    void preorder() { preorder(root); }
    void postorder() { postorder(root); }
};

int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(40);
    tree.insert(50);
    tree.insert(25);
    tree.insert(49);

    cout << "Inorder traversal after insertions: ";
    tree.inorder();
    cout << endl;

    int keyToSearch = 25;
    Node* found = tree.search(keyToSearch);
    if (found)
        cout << "Key " << keyToSearch << " found in the tree.\n";
    else
        cout << "Key " << keyToSearch << " not found.\n";

    tree.deleteKey(40);
    cout << "Inorder traversal after deleting 40: ";
    tree.inorder();
    cout << endl;

    cout << "Preorder traversal: ";
    tree.preorder();
    cout << endl;

    cout << "Postorder traversal: ";
    tree.postorder();
    cout << endl;

    return 0;
}
