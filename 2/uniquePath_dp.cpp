#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int rows = obstacleGrid.size();
        int columns = obstacleGrid[0].size();
        vector<vector<int>>dp(rows,vector<int>(columns));      //load path nums 
        for(int i = 0; i < rows && obstacleGrid[i][0] == 0; ++i){
            dp[i][0] = 1;
        }
        for(int j = 0; j < columns && obstacleGrid[0][j] == 0; ++j){
            dp[0][j] = 1;
        }
        for(int i = 1; i < rows; i++){
            for(int j = 1; j < columns; j++){
                if(obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
                else{
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[rows-1][columns-1];
    }
};

int main()
{
    Solution sol;
    vector<vector<int>>input{{1}};
    int ret = sol.uniquePathsWithObstacles(input);
    cout<<"ret: "<<ret<<endl;
    return 0;
}