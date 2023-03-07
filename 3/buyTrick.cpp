#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans = 0;
        vector<vector<int>>tmp(n,vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(i == j ){
                    tmp[i][j] = 0;
                }
                else{
                    tmp[i][j] = prices[j] - prices[i];
                    ans = max(tmp[i][j],ans);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int>input{7,1,5,3,6,4};
    int ans = sol.maxProfit(input);
    cout<<"ans: "<<ans<<endl;
    return 0;

}

