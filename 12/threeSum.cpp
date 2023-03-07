#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int first = 0; first < n; ++first){
            if(first > 0 && nums[first] == nums[first-1])
            continue;
            int target = -nums[first];
            int third = n-1;
            for(int second = first + 1; second < n; ++second){
                if(second > first+1 && nums[second] == nums[second-1])
                continue;
                while(second < third && (nums[second] + nums[third]) > target){
                    third--;
                }
                if(second == third)
                break;
                if(nums[second] + nums[third] == target){
                    ans.push_back({nums[first],nums[second],nums[third]});
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int>input{-1,0,1,2,-1,-4};
    vector<vector<int>>output = sol.threeSum(input);
    for(vector<vector<int>>::iterator it = output.begin(); it != output.end(); it++ ){
        for(vector<int>::iterator jt = (*it).begin(); jt != (*it).end(); jt++){
            cout<<*jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}