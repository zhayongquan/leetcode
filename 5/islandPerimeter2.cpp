#include<iostream>
#include<vector>

using namespace std;

class Solution {
public: 
    int islandPerimeter(vector<vector<int>>& grid){
        int box = 0;
        int border = 0;
        if(grid.size() == 0)
            return 0;
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 1){
                    box++;
                    //right border
                    if(j+1 < grid[0].size() && grid[i][j+1] == 1){
                        border++;
                    }
                    //up border
                    if(i-1 >= 0 && grid[i-1][j] == 1){
                        border++;
                    }
                }
            }
        }
        return box*4 - border*2;
    }
};

int main(){
    Solution sol;
    vector<vector<int>>input = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
    int ret = sol.islandPerimeter(input);
    cout<<"ret:"<<ret<<endl;
    return 0;
}