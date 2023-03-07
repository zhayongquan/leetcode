#include<iostream>
#include<vector>
#include<numeric>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        int ans = INT32_MAX;
        int sum = 0;
        int start = 0, end = 0;
        while(end < n){
            sum += nums[end];
            while(sum >= target){
                ans = min(ans,end-start+1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};

int main()
{
    Solution sol;
    vector<int>input{2,3,1,2,4,3};
    int ret = sol.minSubArrayLen(7,input);
    cout<<ret<<endl;
    return 0;
}