#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans;
        for(int i = 0; i < n; i++)
        {
            if(target == nums[i])
            {
                ans = i;
                break;
            }
            if(nums[i] > target)
            {
                nums.insert(nums.begin()+ i,target);
                ans = i;
                break;
            }
            else{
                nums.insert(nums.end(),target);
                ans = i+1;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int>v1{1,3,5,6};
    int val = 7;
    int ret = sol.searchInsert(v1,val);
    cout<<"ret: "<<ret<<endl;
    return 0;
}