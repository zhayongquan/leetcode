#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        if(!s.empty()){
            s.erase(s.find_last_not_of(" ")+1);
        }
        int n = s.size();
        reverse(s.begin(),s.end());
        while(!isspace(s[ans]) && ans < n){
            ans++;
        }
    return ans;
    }
};

int main()
{
    string input = "a";
    Solution sol;
    int ret = sol.lengthOfLastWord(input);
    cout<<"ret:"<<ret<<endl;
    return 0;
}