#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }   
        int n = nums.size();
        //cout<<n<<endl;
        vector<int>dp(n, 0);
        dp[0] = nums[0];
        if(nums.size() == 1){
            return nums[0];
        }
        //cout<<nums[0]<<endl;
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n ; i++){
            dp[i] = max(dp[i-1] , dp[i-2] + nums[i]);
        }
        return dp[n-1];
    }
};

int main(){
    Solution sol;
    vector<int>input = {0};
    int ret = sol.rob(input);
    cout<<"ret:"<<ret<<endl;
    return 0;
}