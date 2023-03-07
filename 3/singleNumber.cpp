#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans;
        sort(nums.begin(),nums.end());
        if(n == 1){
            ans = nums[0];
        }
        for(int i = 1; i < n; ++i){
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                ans = nums[i];
            }
            else if(nums[0] != nums[1]){
                ans = nums[0];
            }
            else if(nums[n-1] != nums[n-2]){
                ans = nums[n];
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>input{-336,513,-560,-481,-174,101,-997,40,-527,-784,-283,-336,513,-560,-481,-174,101,-997,40,-527,-784,-283,354};
    int ret = sol.singleNumber(input);
    cout<<"ret: "<<ret<<endl;
    return 0;
}