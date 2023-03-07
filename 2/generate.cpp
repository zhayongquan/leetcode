#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans(numRows);
        for(int i = 0; i < numRows; i++){
            ans[i].resize(i + 1);
            for(int j = 0; j < i+1; j++){
                if(j == 0 || j == i){
                    ans[i][j] = 1;
                }
                else{
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
                }
           }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>>ret = sol.generate(3);
    for(auto it = ret.begin(); it != ret.end(); it++){
        for(auto jt = (*it).begin(); jt !=(*it).end(); jt++){
            cout<<*jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}