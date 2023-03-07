#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n  = s.size();
        int r = numRows;
        //one loop is 2r-2
        int step = 2 * r - 2;
        if(r < 0)
        exit(-1);
        if(r == 1 || r >= n){
            return s;
        }
        
        int add = 0;    //真实前进步数大小
        int ans = 0;    //初始化下标为0
        string ret;     //ret作为返回值
        for(int i = 0; i < r; i++)
        {
            add = i * 2;
            ans = i;
            while(ans < n)
            {
                ret += s[ans];
                add = step - add;
                ans += (i == 0 || i == r - 1) ? step : add;
            }
        }
        return ret;    

    }
};

int main()
{
    Solution sol;
    string ans = sol.convert("LEETCODEISHIRING",4);
    cout<<ans<<endl;
    return 0;
}