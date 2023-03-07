#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int start = 0, end = 0;          //双指针
        while(start < n){
            while(end <n && nums[start] == nums[end]){
                end++;
            }
            if(end - start >= 2){           //大于等于2，尾插2
                fill_n(back_inserter(ans), 2, nums[start]);
            }
            else{                           //小于2，尾插
                fill_n(back_inserter(ans), end-start, nums[start]);
            }
            start = end;
        }
        for(auto it = ans.begin(); it != ans.end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
        nums = ans;
        return ans.size();
    }
};

int main()
{
    Solution sol;
    vector<int>input{1,1,1,2,2,3};
    int ret = sol.removeDuplicates(input);
    cout<<"ret: "<<ret<<endl;
    return 0;
}