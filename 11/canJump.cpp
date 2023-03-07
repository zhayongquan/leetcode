#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        bool ans = true;
        int longest = 0;
        for(int i = 0; i < n; i++){
            if(i > longest) ans = false;
            longest = max(longest,i + nums[i]);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int>input = {2,3,1,1,4};
    bool ret = sol.canJump(input);
    if(ret) cout<<"true!"<<endl;
    else cout<<"false!"<<endl;
    return 0;
}