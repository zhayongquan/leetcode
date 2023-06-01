#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    //2 metheds: 1: if chose 1, can't chose last 1
    // 2: if chose last 1, can't chose 1
    // range wides is 1:[0, n-2], 2:[1,n-1]
    int robrange(vector<int>& nums, int start, int end){
        vector<int>dp(end-start+1, 0);
        int first = nums[start];
        int second = max(nums[start], nums[start+1]);
        for(int i = start + 2; i <= end; i++){
            int temp = second;
            second = max(nums[i] + first, second);
            first = temp;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(nums.size() == 0 ){
            return 0;
        }
        if(nums.size() == 1){
            return nums[0];
        }
        if(nums.size() == 2){
            return max(nums[0],nums[1]);
        }
        return max(robrange(nums,0,n-2), robrange(nums,1,n-1));
    }
};
int main(){
     Solution sol;
    vector<int>input = {1,2,3,1};
    int ret = sol.rob(input);
    cout<<"ret:"<<ret<<endl;
    return 0;
}