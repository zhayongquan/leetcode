#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int>tmp;
    void dfs(int cur, int k, vector<int> &input, vector<vector<int>> &ans){
        if(cur == input.size()){
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(input[cur]);
        dfs(cur+1, k, input, ans);
        tmp.pop_back();
    }
    string getPermutation(int n, int k) {
        vector<int>input(n);
        int factorial = 1;
        for(int i = 1; i <= n; i++){
            input[i] = i;
            factorial *= i;
        }
        vector<vector<int>>ans(factorial);
        dfs(0,k,input,ans);
        string ret = "";
        for(auto it = ans[k].begin(); it != ans[k].end(); it++){
            cout<<*it<<endl;
        }
    }
};

int main(){
    Solution sol;
    sol.getPermutation(3,3);
    return 0;
}