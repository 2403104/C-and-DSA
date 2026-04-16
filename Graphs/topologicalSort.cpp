/**
 * @file topologicalSort.cpp
 * @brief This file contains the implementation of topological sort for a directed acyclic graph (DAG).
 * FOR DIRECTED ACYCLIC GRAPH
 * Topological sorting of a directed graph is a linear ordering of its vertices such that for every directed edge uv from vertex u to vertex v, 
 * u comes before v in the ordering. Topological sorting is possible if and only if the graph has no directed cycles, i.e., it is a Directed Acyclic Graph (DAG).
 * 
 * There are several algorithms to perform topological sorting, including:
 * 
 * 1. **Kahn's Algorithm**:
 *    - This algorithm uses in-degree (number of incoming edges) of nodes.
 *    - Steps:
 *      1. Compute in-degree of all nodes.
 *      2. Initialize a queue with all nodes having in-degree 0.
 *      3. While the queue is not empty:
 *         - Remove a node from the queue and add it to the topological order.
 *         - Decrease the in-degree of all its neighbors by 1.
 *         - If in-degree of any neighbor becomes 0, add it to the queue.
 * 
 * 2. **Depth-First Search (DFS) Based Algorithm**:
 *    - This algorithm uses depth-first search to explore the graph.
 *    - Steps:
 *      1. Initialize a stack to store the topological order.
 *      2. Mark all nodes as unvisited.
 *      3. For each unvisited node, perform DFS:
 *         - Mark the node as visited.
 *         - Recursively visit all its unvisited neighbors.
 *         - After visiting all neighbors, push the node onto the stack.
 *      4. The stack will contain the nodes in topologically sorted order.
 * 
 * The implementation in this file will use one of these algorithms to perform topological sorting on a given DAG.
 * 
 * @note Ensure that the input graph is a DAG before performing topological sort, as the algorithms assume no cycles in the graph.
 * 
 * @see https://en.wikipedia.org/wiki/Topological_sorting
 * 
 * Indegree : No of inward inward directed edges on the vertex in a directed graph
 * Topological Sort is a linear ordering of vertices in a Directed Acyclic Graph (DAG) such that 
 * for every directed edge 𝑢 →𝑣 , vertex u comes before v in the ordering.
 */

#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int>adj[],vector<bool>&vis, stack<int>&st){
    vis[node]=true;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it,adj, vis, st);
        }
    }
    st.push(node);
}

vector<int>topologicalSort(int n, vector<int>adj[]){
    stack<int>st;
    vector<bool>vis(n, false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i,adj,vis, st);
        }
    }
    vector<int>ans;
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}


int main(){
    //directed acyclic graph(if there is any edges between them A->B the A should come before B int this sort)
    


    return 0;
}