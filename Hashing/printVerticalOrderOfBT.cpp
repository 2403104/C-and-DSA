#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

#define vi vector<int>;
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
Node *convertToBT(const vector<int> &v)
{
    if (v.empty())
        return NULL;
    Node *root = new Node(v[0]);
    queue<Node *> q;
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
void printLevelOrder(Node* root){
    if (!root) return ;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<"->";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}
void getVerticalOrder(Node* root,int hdis,map<int,vector<int>> &m) {
    if (root==NULL ) return ;
    m[hdis].push_back(root->data);
    getVerticalOrder(root->left,hdis-1,m);
    getVerticalOrder(root->right,hdis+1,m);
}


int main()
{

vector<int> v={5,4,12,68,7,55,8,1,46,2,586,2};
Node* root=convertToBT(v);  
map<int,vector<int>>m;
int hdis=0;
getVerticalOrder(root ,hdis, m);
map<int,vector<int>>  :: iterator it;
for (it=m.begin();it!=m.end();it++){
    for (auto i : it->second){
        cout<<i<<" ";
    }
    cout<<endl;
}
    return 0;
}