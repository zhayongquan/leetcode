#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    vector<int>t;
    void backtrace(int cur, int n, int k){
        //剪枝
        if(t.size() + (n - cur + 1)  < k)
            return;
        if(t.size() == k){
            ans.push_back(t);
            return;
        }
        if(cur == n + 1){
            return;
        }
        t.push_back(cur);
        backtrace(cur+1,n,k);
        t.pop_back();
        backtrace(cur+1,n,k);
    }
    vector<vector<int>> combine(int n, int k) {
       backtrace(1,n,k);
       return ans ;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>>output = sol.combine(4,2);
    for(auto it = output.begin(); it != output.end(); it++){
        for(auto jt = (*it).begin(); jt != (*it).end(); jt++){
            cout<<*jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}