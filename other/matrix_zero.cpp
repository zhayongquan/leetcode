#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> row(m), col(n);      //m行n列

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!matrix[i][j])
                {
                    row[i] = col[j] = true;
                }
            }
        }

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(row[i] || col[j])
                {
                    matrix[i][j] = 0;
                }
            }
        }

        //print
        for(vector<vector<int>>::iterator it = matrix.begin(); it != matrix.end(); it++)
        {
            for(vector<int>::iterator j = it->begin(); j != it->end(); j++)
            {
                cout<<*j;
            }
            cout<<endl;
        }
    }
};

int main()
{
    Solution sol;
    vector<int>v1{1,1,1};
    vector<int>v2{1,0,1};
    vector<int>v3{1,1,1};
    vector<vector<int>> mat{v1,v2,v3};
    sol.setZeroes(mat);
    return 0;
}