#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        //first loop
        for(int first = 0; first < n; ++first)
        {
            if(first > 0 && nums[first] == nums[first -1])
            {
                continue;
            }
            int target = -nums[first];
            int third = n-1;
            //second loop
            for(int second = first + 1; second < n ; ++second){
                if(second > first + 1 && nums[second] == nums[second - 1]){
                    continue;
                }

                while(second < third && nums[second] + nums[third] > target)
                {
                    third--;
                }

                if(second == third){ 
                    break;
                }

                if(nums[second] + nums[third] == target)
                {
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
    vector<int>input ={-1,0,1,2,-1,-4};
    vector<vector<int>>ret = sol.threeSum(input);
    for(vector<vector<int>>::iterator it = ret.begin(); it != ret.end(); it++)
    {
        cout<<"vector "<<endl;
        for(vector<int>::iterator it2 = (*it).begin(); it2 != ((*it).end()); it2++)
        {
            cout<<*it2<<"\t";
        }
        cout<<endl;

    }
    return 0;
}