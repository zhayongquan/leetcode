#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    vector<vector<int>> res;
    vector<int> temp;

    void backtrack(vector<int>& candidates, int target, int index)
    {
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }
        for(int i = index; i < candidates.size() && target-candidates[i] >= 0; i++)
        {
            cout<<"i:"<<i<<endl;
            cout<<"index:"<<index<<endl;
            if(i > index && candidates[i] == candidates[i-1])
                continue;
            temp.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], i+1);
            temp.pop_back();
        }

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);
        return res;
    }
};

// class Solution {
// public:

//     void dfs(vector<int> &candidates,int target,vector<int>&combine,int index,vector<vector<int>>&ans)
//     {      
//         if(target == 0)
//         {
//             ans.push_back(combine);
//             return;
//         }
//         for(int i = index; i < candidates.size() && target - candidates[i] >= 0; i++)
//         {
//             if(i > index && candidates[i] == candidates[i-1])
//                 continue;
//             combine.push_back(candidates[i]);
//             dfs(candidates,target-candidates[i],combine,i+1,ans);
//             combine.pop_back();
//         }
//     }

//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<vector<int>>ans;
//         vector<int>combine;
//         sort(candidates.begin(),candidates.end());
//         dfs(candidates,target,combine,0,ans);
//         return ans;
//     }
// };

int main()
{
    vector<int>v1{10,1,2,7,6,1,5};
    int a = 8;
    Solution sol;
    vector<vector<int>>ret = sol.combinationSum2(v1,a);
    for(vector<vector<int>>::iterator it = ret.begin(); it != ret.end();it++)
    {
        cout<<"ans:";
        for(int i = 0; i <(*it).size();i++)
        {
            cout<<(*it)[i]<<" ";
        }
        cout<<endl;
    } 

    return 0;
}