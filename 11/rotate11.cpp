#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        auto matrix_new = matrix;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                matrix_new[j][n-i-1] = matrix[i][j];
            }
        }
        matrix = matrix_new;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>>input{{1,2,3},{4,5,6},{7,8,9}};
    sol.rotate(input);
    for(vector<vector<int>>::iterator it = input.begin(); it != input.end();++it)
    {
        for(vector<int>::iterator jt = (*it).begin(); jt != (*it).end(); ++jt)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }

    return 0;
}