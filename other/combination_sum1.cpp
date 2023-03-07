#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void dfs(vector<int> &candidates,int target,vector<int>&combine,int index,vector<vector<int>>&ans)
    {
        if(candidates.size() == index)
        return;
        if(target == 0)
        {   
            // cout<<"one coombine:";
            // for(int i = 0; i < combine.size();i++ )
            // {
            //     cout<<combine[i]<<" ";
            // }
            // cout<<endl;
            ans.emplace_back(combine);
            return;
        }
        dfs(candidates,target,combine,index+1,ans);
        if(target-candidates[index] >= 0)
        {
            cout<<"target : "<<target<<endl;
            cout<<"candidates : "<<candidates[index]<<endl;
            combine.emplace_back(candidates[index]);
            dfs(candidates,target-candidates[index],combine,index,ans);
            // cout<<"the same num:"<<endl;
            // for(int i = 0; i < combine.size();i++ )
            // {
            //     cout<<combine[i]<<" ";
            // }
            // cout<<endl;
            combine.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>combine;
        dfs(candidates,target,combine,0,ans);
        return ans;
    }
};

int main()
{
    vector<int>v1{2,3};
    int a = 8;
    Solution sol;
    vector<vector<int>>ret = sol.combinationSum(v1,a);
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