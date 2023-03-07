#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        //sort(nums.begin(),nums.end());
        int sum = 0;
        int start = 0; int end = 0;
        while(end < n){
            sum += nums[end];
            while(start <= end && sum >= k){
                if(sum == k){
                    ans++;
                }
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int>input{-1,-1,1};
    int ret = sol.subarraySum(input,0);
    cout<<"ret:"<<ret<<endl;
    return 0;
}