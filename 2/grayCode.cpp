#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        //ans = 2^n num
        vector<int>ans(1<<n);
        for(int i = 0; i < ans.size(); i++){
            ans[i] = (i>>1)^i;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>output = sol.grayCode(3);
    for(auto it = output.begin(); it != output.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}