#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>matrix (n,vector<int>(n));  //create n*n matrix
        int num = 1;
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1; 
        while(left <= right && top <= bottom){
            for(int column = left; column <= right; column++){    //top: left->right
                matrix[top][column] = num;
                num++;
            }
            for(int row = top + 1; row <= bottom; row++){         //right: top->bottom
                matrix[row][right] = num;
                num++;
            }
            if(left < right && top < bottom )                     //when n is even_num
            {
                for(int column = right - 1; column > left; column--){      //bottom: right -> left
                    matrix[bottom][column] = num;
                    num++;
                }
                for(int row = bottom; row > top; row--){
                    matrix[row][left] = num;
                    num++;
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return matrix;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>>ans = sol.generateMatrix(3);
    for(vector<vector<int>>::iterator it = ans.begin(); it != ans.end(); it++ ){
        for(vector<int>::iterator jt = (*it).begin(); jt!= (*it).end(); jt++){
            cout<<*jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}