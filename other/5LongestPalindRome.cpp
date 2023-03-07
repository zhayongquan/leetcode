#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2)
        {
            return s;
        }
        int lenmax = 1;
        int begin = 0;
        //创建dp[n][n]，二维数组
        vector<vector<int>> dp (n,vector<int>(n));
         for(int i = 0; i < n; i++)
        {
            dp[i][i] = true;
        }
        //从回文子串为2开始遍历
        for(int L = 2; L <= n; L++){
            //i为左边界值
            for(int i = 0; i < n; i++){
                //回文子串长度L为j-i+1
                int j = L + i -1;
                if(j >= n)
                {
                    break;
                }
                if(s[i] != s[j])
                {
                    dp[i][j] = false;
                }
                else{
                    if(j - i < 3){
                        dp[i][j] = true;
                    }                 
                    else{
                        dp[i][j] = dp[i + 1][j -1 ];
                    }
                }
                //dp[][]为真且长度大于1
                if(dp[i][j] && j - i + 1 >lenmax)
                {
                    lenmax = j - i +1;
                    begin = i;
                }
            }
        }
        return s.substr(begin,lenmax);
    }
};


int main()
{
    Solution sol;
    string ret = sol.longestPalindrome("ababa");
    cout<<"return : "<<ret<<endl;
    return 0;
}