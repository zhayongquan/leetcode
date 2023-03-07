#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
         int ans = 0;
        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // int sum = 1;
        // int start = 0, end = 0;
        // //cout<<"nums[end]:"<<nums[end]<<endl;
        // while(start < n){
        //     //cout<<"nums[end]:"<<nums[end]<<endl;
        //     sum *= nums[end];
        //     //cout<<"sum:"<<sum<<endl;
        //     if(sum < k && end < 4){
        //         ans++;
        //         end++;
        //     }
        //     else{
        //         start++;
        //         end = start;
        //         sum = 1;
        //     }
        // }
        int n = nums.size();
        int sum = 1, i = 0;
        for(int j = 0; j < n; j++){
            sum *= nums[j];
            while(i <= j && sum >=k){
                sum /= nums[i];
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int>input{10,5,2,6};
    int ret = sol.numSubarrayProductLessThanK(input,100);
    cout<<"ret:"<<ret<<endl;
    return 0;
}