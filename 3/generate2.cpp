#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans(rowIndex + 1);
        for(int i = 0; i < rowIndex+1; i++){
            ans[i].resize(i+1);
            for(int j = 0; j < i+1; j++){
                if(j == 0 || j == i){
                    ans[i][j] = 1;
                }
                else{
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
        }
        return ans[rowIndex]; 
    }
};

int main()
{
    Solution sol;
    vector<int>ret = sol.getRow(3);
    for(auto it = ret.begin(); it != ret.end(); it++){
        cout<<*it<<" ";      
    }
    cout<<endl;
    return 0;
}