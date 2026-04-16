# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;

// class Solution {
//     private:
//         Node* dfs(Node* root, unordered_map<Node* , Node*>&mp){
//             vector<Node*>neighbour;
//             Node* clone=new Node(root->val);
//             mp[root]=clone;//to avoid cycle if already created
//             for(auto it :root->neighbors){
//                 if(mp.find(it)!=mp.end()){
//                     neighbour.push_back(mp[it]);
//                 }
//                 else {
//                     neighbour.push_back(dfs(it,mp));
//                 }
//             }
//                 clone->neighbors=neighbour;
//                 return clone;
//         }
//     public:
//         Node* cloneGraph(Node* node) {
//             unordered_map<Node* , Node*>mp;
//             if(node==NULL) return NULL;
//             if(node->neighbors.size()==0){
//                 Node* clone=new Node(node->val);
//                 return clone;
//             }
//             return dfs(node,mp);
//         }
//     };
    
    
    // class Solution {
    // public:
    //     Node* cloneGraph(Node* node) {
    //         if (!node) {
    //             return nullptr;
    //         }
    //         unordered_map<Node*, Node*> visited;
    //         return dfs(node, visited);
    //     }
    
    //     Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
    //         if (visited.find(node) != visited.end()) {
    //             return visited[node];
    //         }
    //         Node* copy = new Node(node->val);
    //         visited[node] = copy;
    //         for (Node* neighbor : node->neighbors) {
    //             copy->neighbors.push_back(dfs(neighbor, visited));
    //         }
    //         return copy;
    //     }
    // };

int main(){

    return 0;
}