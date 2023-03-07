#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < 32; i++){   //遍历32位，每一位和为total
            int total = 0;
            for(int num : nums){
                total += ((num >> i) & 1);   //total 为第i位所有输入数据0，1的和
            }
            if(total % 3){       //不能被i整除，表示为唯一数据
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>input{3,3,3,9};
    int ret = sol.singleNumber(input);
    cout<<"ret: "<<ret<<endl;
    return 0;
}