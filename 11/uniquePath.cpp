#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid (m,vector<int>(n));   //init m*n vector
        for(int i = 0; i < m; i++){
            grid[i][0] = 1;                           //init [i][0] only one path
        }
        for(int j = 0; j < n; j++){
            grid[0][j] = 1;
        }
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                //state transition function
                grid[i][j] = grid[i-1][j] + grid[i][j-1]; 
            }
        }
        return grid[m-1][n-1];         //start with[0],init m*n = [m-1][n-1]
    }
};

int main()
{
    Solution sol;
    int ans = sol.uniquePaths(3,7);
    cout<<"ans:"<<ans<<endl;
    return 0;
}