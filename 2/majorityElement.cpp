#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans;
        int count = 0;
        //key is num,value is num's count
        unordered_map<int,int>counts; 
        for(int num : nums){
            //created key-value unodered_map
            ++counts[num];
            if(counts[num] > count){
                count = counts[num];
                ans = num;
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>input{2,3,4,3,3,3};
    int ret = sol.majorityElement(input);
    cout<<"ret: "<<ret<<endl;
    return 0;
}