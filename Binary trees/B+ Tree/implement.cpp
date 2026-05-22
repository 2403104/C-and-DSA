#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Node structure for the B+ Tree
class Node {
    bool IS_LEAF;
    int *keys;
    int size;
    Node **ptr;
    friend class BPTree;

public:
    Node(int max_degree);
};

// Constructor for Node
Node::Node(int max_degree) {
    // A node can hold max_degree - 1 keys
    keys = new int[max_degree];
    // A node can hold max_degree pointers
    ptr = new Node *[max_degree + 1];
    size = 0;
}

// B+ Tree Class
class BPTree {
    Node *root;
    int MAX; // Order k of the B+ tree

    void insertInternal(int x, Node *cursor, Node *child);
    Node* findParent(Node *cursor, Node *child);

public:
    BPTree(int degree);
    void search(int x);
    void insert(int x);
    void display(Node *cursor);
    Node *getRoot();
};

BPTree::BPTree(int degree) {
    root = NULL;
    MAX = degree;
}

Node *BPTree::getRoot() {
    return root;
}

// Search operation
void BPTree::search(int x) {
    if (root == NULL) {
        cout << "Tree is empty\n";
    } else {
        Node *cursor = root;
        while (cursor->IS_LEAF == false) {
            for (int i = 0; i < cursor->size; i++) {
                if (x < cursor->keys[i]) {
                    cursor = cursor->ptr[i];
                    break;
                }
                if (i == cursor->size - 1) {
                    cursor = cursor->ptr[i + 1];
                    break;
                }
            }
        }
        for (int i = 0; i < cursor->size; i++) {
            if (cursor->keys[i] == x) {
                cout << "Found key: " << x << "\n";
                return;
            }
        }
        cout << "Key " << x << " not found\n";
    }
}

// Insert operation
void BPTree::insert(int x) {
    // If the tree is empty, create a new root node
    if (root == NULL) {
        root = new Node(MAX);
        root->keys[0] = x;
        root->IS_LEAF = true;
        root->size = 1;
    } else {
        Node *cursor = root;
        Node *parent;
        
        // Traverse to the appropriate leaf node
        while (cursor->IS_LEAF == false) {
            parent = cursor;
            for (int i = 0; i < cursor->size; i++) {
                if (x < cursor->keys[i]) {
                    cursor = cursor->ptr[i];
                    break;
                }
                if (i == cursor->size - 1) {
                    cursor = cursor->ptr[i + 1];
                    break;
                }
            }
        }
        
        // If the leaf is not full, simply insert the key
        if (cursor->size < MAX - 1) {
            int i = 0;
            while (x > cursor->keys[i] && i < cursor->size)
                i++;
            for (int j = cursor->size; j > i; j--) {
                cursor->keys[j] = cursor->keys[j - 1];
            }
            cursor->keys[i] = x;
            cursor->size++;
            cursor->ptr[cursor->size] = cursor->ptr[cursor->size - 1];
            cursor->ptr[cursor->size - 1] = NULL;
        } 
        // If the leaf is full, split it
        else {
            Node *newLeaf = new Node(MAX);
            int virtualNode[MAX];
            
            // Copy existing keys and the new key to a virtual node
            for (int i = 0; i < MAX - 1; i++) {
                virtualNode[i] = cursor->keys[i];
            }
            int i = 0, j;
            while (x > virtualNode[i] && i < MAX - 1)
                i++;
            for (int j = MAX - 1; j > i; j--) {
                virtualNode[j] = virtualNode[j - 1];
            }
            virtualNode[i] = x;
            newLeaf->IS_LEAF = true;
            
            // Distribute the keys between the old and new leaf nodes
            cursor->size = (MAX) / 2;
            newLeaf->size = MAX - (MAX) / 2;
            cursor->ptr[cursor->size] = newLeaf;
            newLeaf->ptr[newLeaf->size] = cursor->ptr[MAX - 1];
            cursor->ptr[MAX - 1] = NULL;
            
            for (i = 0; i < cursor->size; i++) {
                cursor->keys[i] = virtualNode[i];
            }
            for (i = 0, j = cursor->size; i < newLeaf->size; i++, j++) {
                newLeaf->keys[i] = virtualNode[j];
            }
            
            // If the cursor is the root, create a new root
            if (cursor == root) {
                Node *newRoot = new Node(MAX);
                newRoot->keys[0] = newLeaf->keys[0];
                newRoot->ptr[0] = cursor;
                newRoot->ptr[1] = newLeaf;
                newRoot->IS_LEAF = false;
                newRoot->size = 1;
                root = newRoot;
            } else {
                // Otherwise, propagate the new key up to the parent
                insertInternal(newLeaf->keys[0], parent, newLeaf);
            }
        }
    }
}

// Helper function to insert into internal nodes
void BPTree::insertInternal(int x, Node *cursor, Node *child) {
    // If the internal node is not full
    if (cursor->size < MAX - 1) {
        int i = 0;
        while (x > cursor->keys[i] && i < cursor->size)
            i++;
        for (int j = cursor->size; j > i; j--) {
            cursor->keys[j] = cursor->keys[j - 1];
        }
        for (int j = cursor->size + 1; j > i + 1; j--) {
            cursor->ptr[j] = cursor->ptr[j - 1];
        }
        cursor->keys[i] = x;
        cursor->size++;
        cursor->ptr[i + 1] = child;
    } 
    // If the internal node is full, split it
    else {
        Node *newInternal = new Node(MAX);
        int virtualKey[MAX];
        Node *virtualPtr[MAX + 1];
        
        for (int i = 0; i < MAX - 1; i++) {
            virtualKey[i] = cursor->keys[i];
        }
        for (int i = 0; i < MAX; i++) {
            virtualPtr[i] = cursor->ptr[i];
        }
        int i = 0, j;
        while (x > virtualKey[i] && i < MAX - 1)
            i++;
        for (int j = MAX - 1; j > i; j--) {
            virtualKey[j] = virtualKey[j - 1];
        }
        virtualKey[i] = x;
        for (int j = MAX; j > i + 1; j--) {
            virtualPtr[j] = virtualPtr[j - 1];
        }
        virtualPtr[i + 1] = child;
        newInternal->IS_LEAF = false;
        
        cursor->size = (MAX - 1) / 2;
        newInternal->size = MAX - 1 - cursor->size;
        
        for (i = 0, j = cursor->size + 1; i < newInternal->size; i++, j++) {
            newInternal->keys[i] = virtualKey[j];
        }
        for (i = 0, j = cursor->size + 1; i < newInternal->size + 1; i++, j++) {
            newInternal->ptr[i] = virtualPtr[j];
        }
        
        if (cursor == root) {
            Node *newRoot = new Node(MAX);
            newRoot->keys[0] = virtualKey[cursor->size];
            newRoot->ptr[0] = cursor;
            newRoot->ptr[1] = newInternal;
            newRoot->IS_LEAF = false;
            newRoot->size = 1;
            root = newRoot;
        } else {
            insertInternal(virtualKey[cursor->size], findParent(root, cursor), newInternal);
        }
    }
}

// Helper function to find the parent of a node
Node* BPTree::findParent(Node *cursor, Node *child) {
    Node *parent;
    if (cursor->IS_LEAF || (cursor->ptr[0])->IS_LEAF) {
        return NULL;
    }
    for (int i = 0; i < cursor->size + 1; i++) {
        if (cursor->ptr[i] == child) {
            parent = cursor;
            return parent;
        } else {
            parent = findParent(cursor->ptr[i], child);
            if (parent != NULL) return parent;
        }
    }
    return parent;
}

// Display function (prints level by level recursively)
void BPTree::display(Node *cursor) {
    if (cursor != NULL) {
        for (int i = 0; i < cursor->size; i++) {
            cout << cursor->keys[i] << " ";
        }
        cout << "\n";
        if (cursor->IS_LEAF != true) {
            for (int i = 0; i < cursor->size + 1; i++) {
                display(cursor->ptr[i]);
            }
        }
    }
}

// Main function to test the tree
int main() {
    // Initialize a B+ Tree of order 4
    BPTree node(4);
    
    // Insert some keys
    int keysToInsert[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    for (int key : keysToInsert) {
        node.insert(key);
    }
    
    // Search for a specific key
    node.search(60); // Output: Found key: 60
    node.search(100); // Output: Key 100 not found
    
    cout << "\nTree Structure (Level by Level DFS Output):\n";
    node.display(node.getRoot());

    return 0;
}