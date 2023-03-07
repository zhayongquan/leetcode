#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        std::vector<int> ret(n+1,0);
        for (int i = 0; i <=n; ++i) {
            ret[i] = ret[i >> 1] + (i & 1);//右移1位相当于i/2
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    vector<int>ret = sol.countBits(2);
    for(vector<int>::iterator it = ret.begin();it!= ret.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}