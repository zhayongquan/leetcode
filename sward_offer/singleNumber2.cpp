#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++){
            int total = 0;
            for(int num : nums){
                // 每次都与000...1与最后一位1做and操作
                total += ((num >> i) & 1);        //0 & 1 = 0； 1 & 1 = 1  check unilligal
            }
            if(total % 3){                        //if 3 times totla % 3 = 0, else one times 1, add this
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int>input{3,3,3,5};
    int ret = sol.singleNumber(input);
    cout<<"ret: "<<ret<<endl;
    return 0;
}