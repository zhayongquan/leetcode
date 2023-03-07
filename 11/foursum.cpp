#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>>ans;
        if(n<4)
        return ans;
        vector<int>part;
        for(int a = 0; a <= n-4; a++){
            if (a>0 && nums[a] == nums[a-1])
            continue;
            for(int b = a+1; b <= n-3;b++){
                if(b>a+1 && nums[b] == nums[b-1])
                continue;
                int c = b+1; int d = n-1; 
                int sum_ab = nums[a]+nums[b]; 
                while(c < d){
                    if(target - sum_ab > nums[c]+nums[d]){
                        c++;
                        if(c > b+1 && nums[c] == nums[c-1])continue;
                    }
                    else if(target - sum_ab < nums[c]+ nums[d]){
                        d--;
                        if(d < n-1 && nums[d] == nums[d+1])continue;
                    }
                    else if(target - sum_ab == nums[c] + nums[d]){
                        ans.push_back({nums[a],nums[b],nums[c],nums[d]});
                        while(c < d && nums[c+1] == nums[c])
                            c++;
                        while(c < d && nums[d-1] == nums[d])
                            d--;
                        c++;
                        d--;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int>nums = {1,0,-1,0,-2,2};
    long long int target = 0;
    vector<vector<int>>ret = sol.fourSum(nums,target);

    for(vector<vector<int>>::iterator it = ret.begin(); it!=ret.end();it++)
    {
        for(vector<int>::iterator jt = (*it).begin(); jt != (*it).end(); jt++){
            cout<<*jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}