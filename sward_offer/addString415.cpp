#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        string ans = "";
        int add = 0;
        while(i >= 0 || j >= 0 || add != 0){
            int x = i >= 0 ? num1[i] - '0' : 0;    //num1[i] - '0'直接通过ascal码将string类型转为int类型
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i--;
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main()
{
    Solution sol;
    string n1 = "11";
    string n2 = "134";
    string ret = sol.addStrings(n1,n2);
    cout<<"ret: "<<ret<<endl;
    return 0;
}