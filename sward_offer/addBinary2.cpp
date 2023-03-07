#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.length()-1;
        int j = b.length()-1;
        int carry = 0;
        while(i >= 0 || j >= 0 || carry != 0 ){
            int x = i >= 0 ? a[i] - '0' : 0;
            int y = j >= 0 ? b[j] - '0' : 0;
            int result = x + y + carry;
            ans.push_back('0' + result % 2);
            carry = result / 2;
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
    string n1 = "1010";
    string n2 = "1011";
    string ret = sol.addBinary(n1,n2);
    cout<<"ret: "<<ret<<endl;
    return 0;
}