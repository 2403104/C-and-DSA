// Sure, here is an explanation of Depth-First Search (DFS):

// Depth-First Search (DFS) is an algorithm for traversing or searching tree or graph data structures. The algorithm starts at the root node (selecting some arbitrary node as the root in the case of a graph) and explores as far as possible along each branch before backtracking.

// Key points about DFS:
// 1. **Traversal Method**: DFS uses a stack data structure, either through recursion or an explicit stack, to keep track of the vertices to be visited next.
// 2. **Exploration**: It explores each branch of a node as deeply as possible before moving on to the next branch.
// 3. **Backtracking**: When it reaches a node with no unvisited adjacent nodes, it backtracks to the previous node to explore other unvisited nodes.
// 4. **Applications**: DFS is used in various applications such as solving puzzles with only one solution, pathfinding, topological sorting, and detecting cycles in graphs.

// DFS can be implemented in both iterative and recursive ways. The recursive implementation is more straightforward but can lead to stack overflow for very deep graphs, while the iterative implementation using an explicit stack can handle deeper graphs more efficiently.
# include <iostream>
# include <algorithm>
# include <vector> 
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;
void dfs(int node, vector<int>adj[],vector<int>&vis, vector<int>&ans){
    vis[node]=1;
    ans.push_back(node);
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj,vis,ans);
        }
    }
}
vector<int>dfsOfGraph(int n, vector<int>adj[]){
    vector<int>vis(n,0);
    vector<int>ans;
    int start=0;
    dfs(start, adj,vis, ans);
    return ans;
}
int main(){

    return 0;
}