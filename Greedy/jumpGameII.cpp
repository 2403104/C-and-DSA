# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <map>
# include <unordered_map>
# include <queue>
# include <stack>
using namespace std;

int minJumps1(vector<int>& arr, int idx, int jumps) {
    int n = arr.size();
    if (idx >= n - 1) return jumps;  // Base Case: If we reach or cross the last index, return jumps taken.
    int mini = INT16_MAX;  // Initialize minimum jumps to a very large value.
    for (int i = 1; i <= arr[idx]; i++) {  // Try all possible jumps from this position
        mini = min(mini, minJumps1(arr, idx + i, jumps + 1));  // Recursively check the minimum jumps needed
    }
    return mini;
}

int minJumps2(vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) return 0;
    if (arr[0] == 0) return -1;  // If first index is 0, we can't move.

    int maxReach = arr[0], steps = arr[0], jumps = 1;

    for (int i = 1; i < n; i++) {
        if (i == n - 1) return jumps;  // If we reach the last index
        
        maxReach = max(maxReach, i + arr[i]); // Update max reachable index
        steps--;  // Use one step
        
        if (steps == 0) {  // If no more steps left
            jumps++;  // We must jump
            if (i >= maxReach) return -1;  // If we can't move further
            steps = maxReach - i;  // Reset steps
        }
    }
    return -1;
}


int main(){
    vector<int>arr={2,3,1,1,4};
    cout<<minJumps1(arr, 0, 0);


    return 0; 
}

