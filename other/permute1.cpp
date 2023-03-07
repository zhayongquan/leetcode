#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>>ans;

    void backtrack(vector<int>& output,int first,int len)
    {

    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        backtrack(nums,0,n);
        return ans;
    }
};

int main()
{
    return 0;
}