# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
bool issafe(int** arr,int x,int y, int  n){
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}
bool ratinmaze(int** arr,int x, int y, int n,int** solution){
    if (x==n-1 && y==n-1){
        solution[x][y]=1;
        return true;
    }
    if (issafe(arr,x,y,n)){
        solution[x][y]=1;
        if (ratinmaze(arr,x+1, y, n, solution)){
            return true;//yadi rashta mil raha to true return kar denge
        }
        if (ratinmaze(arr,x,y+1, n,solution)){
            return true;
        }
        solution[x][y]=0;//backtracking(dono se rashta yadi nahi mila to )
        return false;
    }
    return false;//(if x,y is not safe)
}
int main(){
int nums[5][5]={{1,0,1,0,1},{1,1,1,1,1},{0,1,1,0,1},{1,0,0,1,1},{1,1,1,0,1}};
int sol[5][5]={{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
// if (ratinmaze(nums,0,0,5,sol)){
//     for(int i=0;i<5;i++){
//         for(int j=0;j<5;j++){
//             cout<<sol[i][j]<<" ";
//         }
//         cout<<endl;
//     }
// }


    return 0;
}