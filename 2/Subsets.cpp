#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>t;
    void dfs(int cur, vector<int>& nums){
        if(cur == nums.size()){
            ans.push_back(t);
            return;
        }
        t.push_back(nums[cur]);
        dfs(cur + 1, nums);
        t.pop_back();
        dfs(cur + 1, nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int>input{1,2,3};
    vector<vector<int>>output = sol.subsets(input);
    for(auto it = output.begin(); it != output.end(); it++){
        for(auto jt = (*it).begin(); jt != (*it).end(); jt++){
            cout<<*jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}


// class Solution {
// public:
//     vector<int> t;
//     vector<vector<int>> ans;

//     void dfs(int cur, vector<int>& nums) {
//         if (cur == nums.size()) {
//             ans.push_back(t);
//             return;
//         }
//         t.push_back(nums[cur]);        //考虑当前选择
//         dfs(cur + 1, nums);
//         t.pop_back();
//         dfs(cur + 1, nums);            //不考虑当前选择
//     }

//     vector<vector<int>> subsets(vector<int>& nums) {
//         dfs(0, nums);
//         return ans;
//     }
// };

