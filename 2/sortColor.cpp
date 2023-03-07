#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int>cover;
        int z_count = 0, o_count = 0, t_count = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                z_count++;
            else if(nums[i] == 1)
                o_count++;
            else if(nums[i] == 2)
                t_count++;
        }
        cover.insert(cover.begin(),z_count,0);
        cover.insert(cover.end(),o_count,1);
        cover.insert(cover.end(),t_count,2);
        nums = cover;
    }
};

int main()
{
    Solution sol;
    vector<int>input{2,0,2,1,1,0};
    sol.sortColors(input);
    for(auto it = input.begin(); it != input.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}