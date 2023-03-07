#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int best = 1e7;
        int n = nums.size();
        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target)) {
                best = cur;
            }
        };

        for(int first = 0; first < n; ++first)
        {
            if(first > 0 && nums[first] == nums[first -1])
            {
                continue;
            }

            int third = n - 1;
            //second loop
            for(int second = first + 1; second < n ; ++second){
                if(second > first + 1 && nums[second] == nums[second - 1]){
                    continue;
                }
                while (second < third)
                {
                    int sum = nums[first] + nums[second] + nums[third];
                    if(sum == target)
                    {
                        return target;
                    }
                    update(sum);
                if (sum > target) {
                    // 如果和大于 target，移动 c 对应的指针
                    int k0 = third - 1;
                    // 移动到下一个不相等的元素
                    while (second < k0 && nums[k0] == nums[third]) {
                        --k0;
                    }
                    third = k0;
                    } 
                    else {
                    // 如果和小于 target，移动 b 对应的指针
                    int j0 = second + 1;
                    // 移动到下一个不相等的元素
                    while (j0 < second && nums[j0] == nums[second]){
                        ++j0;
                    }
                    second = j0;
                }

                }
            }
        }
        return best;
    }
};

int main()
{
    Solution sol;
    vector<int>v1= {-1,2,1,-4};
    int ret = sol.threeSumClosest(v1,1);
    cout<<"ret: "<<ret<<endl;
    return 0;
}