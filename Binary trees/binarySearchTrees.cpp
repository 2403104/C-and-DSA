# include <iostream>
# include <vector>
# include <climits>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* insertBST(Node* root, int val){
    if (root==NULL){
        return new Node(val);
    }
    if (val<root->data){
        root->left=insertBST(root->left,val);
    }
    else{
        root->right=insertBST(root->right,val);
    }
    return root;
}
//inorder of bst alway gives the array in increasing order
void inOrder(Node* root){
    if (root==NULL) return ;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
void preOrder(Node* root){
    if (root==NULL) return ;
    cout<<root->data;
    preOrder(root->left);
    preOrder(root->right);
}
//SEARCH (log(n+1)) n==number of nodes
bool searchInBST(Node* root,int key){
    if (root==NULL) return false;
    if (root->data==key) return true;
    if (key<root->data) searchInBST(root->left,key);
    else searchInBST(root->right,key);
}
//DELETE 
//inOrdere successor means the number which comes after that node in the inorder traversal
Node* inOrderSucc(Node* root){
    Node* curr=root;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node* deleteInBST(Node* root, int key){
    if (root==NULL ) return root;
    if (key<root->data){
        root->left=deleteInBST(root->left,key);
    }
    else if (key>root->data){
        root->right=deleteInBST(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if (root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        Node* temp=inOrderSucc(root->right);//finding smallest in the right subtree of the node
        root->data=temp->data;
        root->right=deleteInBST(root->right,temp->data);
    }
    return root;
}

//BUILT BST FROM PREORDER
Node* constructBST(int preOrder[],int* preOrderIdx, int key, int min, int max,int n){
    if (*preOrderIdx>=n) return NULL;
    Node* root= NULL;
    if (key>min && key<max){
        root=new Node (key);
        *preOrderIdx=*preOrderIdx+1;
        if (*preOrderIdx<n){
            root->left=constructBST(preOrder,preOrderIdx,preOrder[*preOrderIdx],min, key, n);
        }
        if (*preOrderIdx<n){
            root->right=constructBST(preOrder,preOrderIdx, preOrder[*preOrderIdx],key, max, n);
        }
    }
    return root;
}

bool checkBST1(Node* root){
    if (root==NULL ) return true;
    if(root->right!=NULL && root->data>=root->right->data) return false;
    if (root->left!=NULL && root->data<=root->left->data) return false;
    return checkBST1(root->left) && checkBST1(root->right);
}

bool checkBST2(Node* root,Node* min,Node* max){
    if (root==NULL ) return true;
    if (min!=NULL  && root->data<=min->data){
        return false;
    }
    if (max!=NULL && root->data>=max->data){
        return false;
    }
    bool leftValid=checkBST2(root->left,min,root);
    bool rightValid=checkBST2(root->right,root,max);
    return leftValid && rightValid;
}

//BUILD BST FROM SORTED ARRAY
Node* sortedArrayToBST(int arr[],int start, int end){
    if (start>end) return NULL;
    int mid=(start+end)/2;
    Node* root=new Node(arr[mid]);
    root->left=sortedArrayToBST(arr, start, mid-1);
    root->right=sortedArrayToBST(arr, mid+1, end);
    return root;
}
//CATALAN NUMBERS
// 1 1 2 5 14 starting from zero
int catalan(int n){
    if ( n<=1) return 1;
    int res=0;
    for (int i=0;i<=n-1;i++){
        res+=catalan(i)*catalan(n-i-1);
    }
    return res;
}
vector<Node*> constructTrees(int start, int end){
    vector<Node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++){
        vector<Node*>leftSubtrees=constructTrees(start,i-1);
        vector<Node*>rightSubtrees=constructTrees(i+1,end);

        for(int j=0;j<leftSubtrees.size();j++){
            Node* left=leftSubtrees[j];
            for(int k=0;k<rightSubtrees.size();k++){
                Node* right=rightSubtrees[k];
                Node* node=new Node(i);
                node->left=left;
                node->right=right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}
    void cta(Node* root,vector<int>&v){
        if(!root) return ;
        v.push_back(root->data);
        if(root->left) cta(root->left,v);
        if(root->right) cta(root->right,v);
    }
bool identicalBST(Node* root1, Node* root2){
    if(!root1 && !root2) return true;
    if(root1 && !root2) return false;
    if(root2 &&  !root1) return false;
    if(root1->data!=root2->data) return false;
    return identicalBST(root1->left, root2->left) && identicalBST(root1->right, root2->right);
}
bool checkBST(Node* root){
    if(!root) return true;
    if(root->left){
        if(root->left->data>root->data) return false;
    }
    if(root->right){
        if(root->right->data<root->data) return false;
    }
    return checkBST(root->left) && checkBST(root->right);
}
//LARGEST BST IN BT



int main(){
    Node* root1=NULL;
    root1=insertBST(root1,5);
    insertBST(root1,1);
    insertBST(root1,3);
    insertBST(root1,4);
    insertBST(root1,2);
    insertBST(root1,7);  

    Node* root2=NULL;
    root2=insertBST(root2,5);
    insertBST(root2,2);
    insertBST(root2,3);
    insertBST(root2,4);
    insertBST(root2,2);
    cout<<checkBST1(root2);
    // inOrder(root);
    // cout<<searchInBST(root,14);
    // root=deleteInBST(root,2);
    // inOrder(root);
    // int preOrderSeq[]={10,2,1,13,11};
    // int n=5;
    // int preOrderIdx=0;
    // Node* root=constructBST(preOrderSeq,&preOrderIdx,preOrderSeq[0],INT16_MIN,INT16_MAX,n);
    // inOrder(root);
    // cout<<checkBST2(root,NULL,NULL );
    // int arr[]={10,20,30,40,50};
    // inOrder(sortedArrayToBST(arr,0,4));
    // for (int i=0;i<10;i++){
    //     cout<<catalan(i)<<" ";
    // }
    
    // preOrder(root1);
    // cout<<endl;
    // preOrder(root2);

    return 0;
}