#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int ans = 0;
    int sum_path = 0;
    void dfs(int row, int column, int sum_path, vector<vector<int>>& obstacleGrid){\
        if(row == obstacleGrid.size() - 1 && column == obstacleGrid[0].size() - 1 ){
            ans++;
            return;
        }
        // barrier, to return
        if(sum_path != 0){
            return;
        }
        // right move
        if(row < obstacleGrid.size() - 1 ){
            sum_path += obstacleGrid[row+1][column]; 
            //cout<<"enter row! ans is :"<<ans<<endl; 
            dfs(row + 1, column, sum_path, obstacleGrid);
            //cout<<"exit row ! ans is :"<<ans<<endl;
            sum_path -= obstacleGrid[row+1][column];       //back
        }
        if(column < obstacleGrid[0].size() - 1){
            sum_path += obstacleGrid[row][column+1];
            //cout<<"enter column! ans is :"<<ans<<endl;
            dfs(row, column + 1, sum_path, obstacleGrid);
            //cout<<"exit cloumn! ans is :"<<ans<<endl;
            sum_path -= obstacleGrid[row][column+1];
        }

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        cout<<"11"<<endl;
        if(obstacleGrid[m-1][n-1] == 0 && obstacleGrid[0][0] == 0){
             cout<<"22"<<endl;
            dfs(0,0,0,obstacleGrid);
        }
        
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>>input {{0,0,0},{0,1,0},{0,0,0}};
    int ret = sol.uniquePathsWithObstacles(input);
    cout<<"ret: "<<ret<<endl;
    return 0;
}