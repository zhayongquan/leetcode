#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>t;
    void dfs(bool choosePre,int cur, vector<int>& nums){
        if(cur == nums.size()){
            ans.push_back(t);
            return;
        }
        dfs(false, cur + 1, nums);                                  //not load nums[cur].
        if(!choosePre && cur > 0 && nums[cur - 1] == nums[cur]){    //if nums[cur-1] == nums[cur] and
            return;                                                 //nums[cur-1] not load , so nums[cur]
        }                                                           //also not load.
        //load nums[cur]
        t.push_back(nums[cur]);
        dfs(true, cur + 1, nums);
        t.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        dfs(false,0,nums);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int>input{1,2,2};
    vector<vector<int>>output = sol.subsetsWithDup(input);
    for(auto it = output.begin(); it != output.end(); it++){
        for(auto jt = (*it).begin(); jt != (*it).end(); jt++){
            cout<<*jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}


