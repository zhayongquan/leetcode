#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    vector<int>twoSum(vector<int>&nums, int target)
    {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if(nums[i] > target)
                break;
            int tar = target - nums[i];
            for(int j = i + 1; j < n; ++j){
                if(nums[j] == tar){
                    ans.push_back(i);
                    ans.push_back(j);
                }
                if(nums[j] > tar)
                break;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int>input{1,2,4,6,10};
    vector<int>output = sol.twoSum(input,8);
    for(vector<int>::iterator it = output.begin(); it != output.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}