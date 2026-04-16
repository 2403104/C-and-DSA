// class Solution {
// public:
//     int depth(TreeNode* root){
//         if(!root) return 0;
//         return 1+max(depth(root->left),depth(root->right));
//     }
//     void solve(TreeNode* root , int curr, int h,vector<TreeNode*> &v){
//         if(!root) return ;
//         if(curr==h){
//              v.push_back(root);
//              return;
//         }
//         curr+=1;
//         solve(root->left,curr,h,v);
//         solve(root->right,curr,h,v);
//     }
//     TreeNode* findLca(TreeNode* root,unordered_set<int>&tSet ){
//         if(!root) return NULL;
//         if(tSet.count(root->val)) return root;
//         TreeNode* left=findLca(root->left,tSet);
//         TreeNode* right=findLca(root->right,tSet);
        
//         if(left&&right) return root;
//         return left?left:right;
//     }
//     TreeNode* lca(TreeNode* root, vector<TreeNode*>&nodes){
//         unordered_set<int>tSet;
//         for(auto i:nodes) tSet.insert(i->val);
//         return findLca(root,tSet);
//     }
//     TreeNode* subtreeWithAllDeepest(TreeNode* root) {
//         vector<TreeNode*> v;
//         solve(root, 1,depth(root),v);
        
//         return lca(root,v);
//     }
// };