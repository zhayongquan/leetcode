#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string prev = "1";
        for(int i = 2; i <= n; i++){
            string cur = "";
            int start = 0;
            int pos = 0 ;

            while(pos < prev.size())           //统计每一个n的表示
            {
                while(pos < prev.size() && prev[pos] == prev[start]){
                    pos++;
                }
                cur += to_string(pos-start) + prev[start];
                start = pos;
            }
            prev = cur;
        }
        return prev;
    }
};

int main()
{
    Solution sol;
    string ans = sol.countAndSay(4);
    cout<<"ans:"<<ans<<endl;
    return 0;
}