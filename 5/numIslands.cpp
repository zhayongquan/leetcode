#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int island_num = 0;
    void dfs(vector<vector<char>>& grid, int r, int c){
        int nr = grid.size();
        int nc = grid[0].size();
        
        grid[r][c] = '0';
        if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
        if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
        if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
        if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
            return 0;
        int len = grid.size();
        int wid = grid[0].size();
        for(int i = 0; i < len; i++){
            for(int j = 0; j < wid; j++){
                if(grid[i][j] == '1'){
                    island_num++;
                    dfs(grid,i,j);
                }
            }
        }
        return island_num;
    }
};

int main(){
    vector<vector<char>>input = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    Solution sol;
    int ret = sol.numIslands(input);
    cout<<"ret: "<<ret<<endl;
    return 0;
}