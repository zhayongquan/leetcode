#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:

    int dfs(vector<vector<int>>& grid,int r, int c, int len, int wid){
        if(r < 0 || r >= len || c < 0 || c >= wid || grid[r][c] != 1){
            return 0;
        }
        grid[r][c] = 2;
        int ans = 1;

        //陆地四个方向进行遍历
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
         for(int i = 0; i < 4; ++i){
            int tx = r + dx[i];
            int ty = c + dy[i];
            ans += dfs(grid, tx, ty,len,wid);
        } 
        return ans;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        int len = grid.size();
        int wid = grid[0].size();
        int area = 0;
        for(int i = 0; i < len; i++){
            for(int j = 0; j < wid; j++){   
                area = max(area,dfs(grid,i,j,len,wid));
            }
        }
        return area;
    }
};

int main(){
    Solution sol;
    vector<vector<int>>input = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    int ret = sol.maxAreaOfIsland(input);
    cout<<"ret:"<<ret<<endl;
    return 0;
}