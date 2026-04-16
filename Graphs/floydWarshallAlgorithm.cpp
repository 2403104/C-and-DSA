/*
This function uses the Floyd-Warshall algorithm to find the shortest paths between all pairs of nodes in a graph.
-1 is used to represent "no direct path" between two nodes in the graph.
matrix[i][j] = -1 means there is no direct edge from node i to node j.
*/
#include <bits/stdc++.h>
using namespace std;
void floydWarshall(vector<vector<int>>&matrix){
    int n=matrix.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==-1){
                matrix[i][j]=1e9;
            }
            if(i==j) matrix[i][j]=0;
        }
    }
    for(int k=0;k<n ;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1e9){
                matrix[i][j]=-1;
            }
        }
    }
}
int main(){
    vector<vector<int>> matrix = {
        {0, 3, -1, 7},
        {-1, 0, 2, -1},
        {-1, -1, 0, 1},
        {-1, -1, -1, 0}
    };
    floydWarshall(matrix);
    for(auto i : matrix){
        for(auto j : i) cout<<j<<" ";
        cout<<endl;
    }


    return 0;
}
//can't detect negative cycle