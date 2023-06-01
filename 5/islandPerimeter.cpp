#include<iostream>
#include<vector>

using namespace std;

class Solution {
    // use to 4 front dfs
      int dx[4] = {0, 1, 0, -1};
      int dy[4] = {1, 0, -1, 0};
public:

    int dfs(int row,int col,vector<vector<int>>& grid, int r, int c){
        //对四个方向进行判断，如果为边界或者为水域则加1
        if(r < 0 || r >= row || c < 0 || c >= col || grid[r][c] == 0){
            return 1;
        }
        if(grid[r][c] == 2){
             return 0;
        }
        //when grid[r][c] == 1, mark this grid is travered, set 1 -> 2
        grid[r][c] = 2;
        // 四个方向进行dfs
        int res = 0;
        for(int i = 0; i < 4; ++i){
            int tx = r + dx[i];
            int ty = c + dy[i];
            res += dfs(row, col, grid, tx, ty);
        } 
        return res;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int perimeter = 0;
        if(grid.size() == 0)
            return 0;
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    perimeter += dfs(row,col,grid,i,j);
                }
            }
        }
        return perimeter;
    }
};

int main(){
    Solution sol;
    vector<vector<int>>input = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    int ret = sol.islandPerimeter(input);
    cout<<"ret:"<<ret<<endl;
    return 0;
}