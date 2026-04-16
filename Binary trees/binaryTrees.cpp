#include <bits/stdc++.h>
#include <queue>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* lowestCommonTreeBT(TreeNode* root, TreeNode* p, TreeNode*q){
    if(!root || p==root || q==root) return root;
    TreeNode* l=lowestCommonTreeBT(root->left,p,q);
    TreeNode* r=lowestCommonTreeBT(root->right,p,q);
    if(l && r) return root;
    return l?l:r;
}
void postorderOneStack(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> st;
    TreeNode* lastVisited = nullptr;
    TreeNode* curr = root;

    while (!st.empty() || curr != nullptr) {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        } else {
            TreeNode* peek = st.top();
            if (peek->right != nullptr && lastVisited != peek->right) {
                curr = peek->right;
            } else {
                cout << peek->val << " ";
                lastVisited = peek;
                st.pop();
            }
        }
    }
}
void postorderTwoStacks(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left) s1.push(curr->left);
        if (curr->right) s1.push(curr->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->val << " ";
        s2.pop();
    }
}

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
// root left right
void preOrder(struct Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// left root right
void inOrder(struct Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// left right root
void postOrder(struct Node *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << root->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
                q.push(node->right);
        }
        else if (!q.empty())
            q.push(NULL);
    }
}
void printLevelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->data << "->";
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    cout << endl;
}
int sumAtLevel(Node *root, int k)
{
    if (root == NULL)
        return 0;
    queue<Node *> q;
    int ans = 0;
    q.push(root);
    q.push(NULL);
    while (!q.empty() && k >= 0)
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            ans += node->data;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        else
        {
            k--;
            if (!q.empty())
                q.push(NULL);
        }
    }
    return ans;
}
int countNodes(Node *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
int sumNodes(Node *root)
{
    if (!root)
        return 0;
    return root->data + sumNodes(root->left) + sumNodes(root->right);
}
int heightBinaryTree(Node *node)
{
    if (!node)
        return 0;
    int leftHeight = heightBinaryTree(node->left);
    int rightHeight = heightBinaryTree(node->right);
    return max(leftHeight, rightHeight) + 1;
}
// diameter=number of nodes in the longest path between any two leaves
int calcHeight(Node *root)
{
    if (!root)
        return 0;

    return max(calcHeight(root->left), calcHeight(root->right)) + 1;
}
int calcDiameter(Node *root)
{
    if (!root)
        return 0;
    int lHeight = calcHeight(root->left);
    int rHeight = calcHeight(root->right);

    int currDiameter = lHeight + rHeight + 1;

    int lDiamter = calcDiameter(root->left);
    int rDiameter = calcDiameter(root->right);
    return max(currDiameter, max(lDiamter, rDiameter));
}
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (!root || root == p || root == q) return root;

    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) return root;
    return left ? left : right;
}

void sumReplacement(Node *root)
{
    if (!root)
        return;
    sumReplacement(root->left);
    sumReplacement(root->right);

    if (root->left)
        root->data += root->left->data;
    if (root->right)
        root->data += root->right->data;
}
// O(n*n)
// bool isBalanced(Node* root){
//     if (!root) return true;
//     if(!isBalanced(root->left)) return false;
//     if (!isBalanced(root->right)) return false;

//     int lHeight=heightBinaryTree(root->left);
//     int rHeight=heightBinaryTree(root->right);

//     if ( ! abs(lHeight-rHeight)<=1) {
//         return true;
//     }else{
//         return false;
//     }

//     isBalanced(root->left);
//     isBalanced(root->right);
// }

// O(n)
bool isBalanced(Node *root, int *height)
{
    if (!root)
        return true;
    int lh = 0, rh = 0;
    if (!isBalanced(root->left, &lh))
        return false;
    if (!isBalanced(root->right, &rh))
        return false;
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void rightView(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *node = q.front();
            q.pop();
            if (i == n - 1)
            {
                cout << node->data << " ";
            }
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
}

void leftView(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (i == 0)
                cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
// min number of edges to be traversed to reach node2 from node1

// flatten binary tree to linked list(in preorder)
// without using extra data structure
// void flatten(Node *root)
// {
//     if ((root->left == NULL && root->right == NULL) || root == NULL)
//         return;
//     if (root->left)
//     {
//         flatten(root->left);
//         Node *temp = root->right;
//         root->right = root->left;
//         root->left = NULL;

//         Node *t = root->right;
//         while (t->right)
//             t = t->right;
//         t->right = temp;
//     }
//     flatten(root->right);
// }

// void flatten(TreeNode* root) {
//     if (root==NULL){
//         return ;
//     }
//     flatten(root->left);
//     flatten(root->right);
//     if (root->left){
//         TreeNode* temp=root->right;
//         root->right=root->left;
//         root->left=NULL;
//         TreeNode* rt=root->right;
//         while(rt->right){
//             rt=rt->right;
//         }
//         rt->right=temp;
//     };
// Case 1: Print all subtree nodes at distance 'k'
void printSubtreeNodes(Node *root, int k)
{
    if (root == NULL || k < 0)
        return;
    if (k == 0)
    {
        cout << root->data << " "; // Base case: Found a node at distance k
        return;
    }
    // Recur for left and right subtrees with reduced k
    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);
}

// Case 2: Print all nodes at distance 'k' from the target node
int printNodesAtk(Node *root, Node *target, int k)
{
    if (root == NULL)
        return -1;

    // Base case: Target node found
    if (root == target)
    {
        printSubtreeNodes(root, k); // Print subtree nodes at distance k
        return 0;                   // Distance of target from itself is 0
    }

    // Recur for left subtree
    int dl = printNodesAtk(root->left, target, k);
    if (dl != -1)
    {
        // Check if the current node is at the required distance
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            // Print nodes in the right subtree at distance k - dl - 2
            printSubtreeNodes(root->right, k - dl - 2);
        }
        return 1 + dl; // Increment the distance and propagate up
    }

    // Recur for right subtree
    int dr = printNodesAtk(root->right, target, k);
    if (dr != -1)
    {
        // Check if the current node is at the required distance
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            // Print nodes in the left subtree at distance k - dr - 2
            printSubtreeNodes(root->left, k - dr - 2);
        }
        return 1 + dr; // Increment the distance and propagate up
    }

    return -1; // Target node not found in either subtree
}
// method 1
bool getPath(Node *root, Node* key, vector<Node*> &path)
{
    if (root == NULL)
        return false;
    path.push_back(root);
    if (root == key)
    {
        return true;
    }
    if (getPath(root->left, key, path) || getPath(root->right, key, path))
    {
        return true;
    }
    path.pop_back();
    return false;
}

Node* lowestCommonIncesstor(Node *root, Node* n1, Node* n2)
{
    vector<Node*> path1;
    vector<Node*> path2;
    if (!getPath(root, n1, path1) || !getPath(root, n2, path2))
    {
        return NULL;
    }
    int pc; // path change
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
            break;
    }
    return path1[pc - 1];
}
int findDistance(Node* root, Node* p){
    if(!root) return -1;
    if(root==p) return 0;
    return 1+min(findDistance(root->left,p),findDistance(root->right,p));
}
int findMinDist(Node* root, Node* p, Node* q){
    if(!root) return -1;
    Node* lca=lowestCommonIncesstor(root,p,q);
    Node* tempLeft=lca;
    Node* tempRight=lca;
    int disP=findDistance(root,p);
    int disQ=findDistance(root,q);
    return disP+disQ;
}
// method 2
Node *LCA2(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if ((root->data == n1) || (root->data == n2))
    {
        return root;
    }
    Node *left = LCA2(root->left, n1, n2);
    Node *right = LCA2(root->right, n1, n2);

    if (left && right)
    {
        return root;
    }
    if (left)
        return left;
    return right;
}
int maxPathSumUtil(Node *root, int &ans)
{
    if (root == NULL)
        return 0;
    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);
    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));
    ans = max(ans, nodeMax);
    int singlePathSum = max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;
}
int maxPathSum(Node *root)
{
    int ans = INT16_MIN;
    maxPathSumUtil(root, ans);
    return ans;
}
void populate(Node *root, vector<int> &ans)
{
    if (!root)
        return;
    ans.push_back(root->data);
    populate(root->left, ans);
}
vector<int> convertToLeftArray(Node *root)
{
    vector<int> ans;
    populate(root, ans);
    return ans;
}
Node *arrayToBT(const vector<int> &v)
{
    if (v.empty())
        return NULL;
    queue<Node *> q;
    Node *root = new Node(v[0]);
    q.push(root);
    int i = 1;
    while (!q.empty() && i < v.size())
    {
        Node *curr = q.front();
        q.pop();
        if (i < v.size())
        {
            curr->left = new Node(v[i++]);
            q.push(curr->left);
        }
        if (i < v.size())
        {
            curr->right = new Node(v[i++]);
            q.push(curr->right);
        }
    }
    return root;
}
void findLeafNodes(Node *&root)
{
    vector<int> ans;
    if (!root)
        return;
    ans.push_back(root->data);
    findLeafNodes(root->left);
    findLeafNodes(root->right);
}
void maxPathSum(Node* root, int& maxm,int curr){
     if(!root) return;
     curr+=root->data;
     maxm=max(maxm,curr);
     maxPathSum(root->left,maxm,curr);
     maxPathSum(root->right,maxm,curr);
}
int main()
{
    /*
                             1
                           /   \
                          2      3
                        /   \  /   \
                       4    5 6     7
                     /
                    8
    */
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->left->left = new Node(8);
    int maxm=0;
    maxPathSum( root, maxm,0);
    cout<<maxm;
    // vector<int> ans=convertToLeftArray(root);
    // for (auto i : ans) cout<<i<< " ";
    // int preOrder[]={1,2,4,3,5};
    // int inOrder[]={4,2,1,5,3};

    // levelOrder(root);
    // cout<<sumAtLevel(root,2);
    // cout<<sumNodes(root);
    // cout<<heightBinaryTree(root);
    // cout<<calcDiameter(root);
    // levelOrder(root);
    // cout<<endl;
    // sumReplacement(root);
    // levelOrder(root);
    // int height=0;
    // cout<<isBalanced(root,&height);
    // rightView(root);
    // leftView(root);

    // int n1=7,n2=6;
    // cout<<lowestCommonIncesstor(root,n1,n2);
    // cout<<maxPathSum(root);
    // vector<int> v={2,1,4,5,3,6,9,7,8};
    // Node* ans=arrayToBT(v);
    // printLevelOrder(ans);
    // inOrder(ans);


    return 0;
}