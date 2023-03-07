#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.size();
        int lenp = p.size();
        vector<vector<bool>>dp(lens+1,vector<bool>(lenp+1,false));
        dp[0][0] = true;   //空串为true
        for(int j = 1; j < lenp+1; j++){     //s为空，p串因为"*"消灭前面字符，变为空，与s串匹配
            if(p[j] == '*'){
                dp[0][j+1] == dp[0][j-1];
            }
        }
        for(int i = 1; i < lens+1; ++i){
            for(int j = 1; j < lenp+1; ++j){
                if(s[i-1] == p[j-1] || p[j-1] == '.'){   //情况1，符合进行更新
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1] == '*'){                       //     情况2，有*形式
                    if(s[i-1]==p[j-2]||p[j-2]=='.'){
                        dp[i][j] = dp[i][j-2]||dp[i-1][j-2]||dp[i-1][j];
                    }
                    else{                            //s[i-1] p[j-2]不匹配  *需要重复0次
                        dp[i][j] = dp[i][j-2];
                    }
                }
            }
        }
        return dp[lens][lenp];
    }
};

int main(){
    Solution sol;
    bool ret;
    string s = "aa";
    string p = "ab";
    ret = sol.isMatch(s,p);
    if(ret){
        cout<<"true!"<<endl;
    }
    else{
        cout<<"false!"<<endl;
    }
    return 0;
}