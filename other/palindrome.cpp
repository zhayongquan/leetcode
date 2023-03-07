#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
        {
            return false;
        }

        stringstream ss;
        ss << x;
        string str,reverseStr;
        ss >> str;

        int strsize = str.size();
        for(int index = strsize - 1;index >= 0;index --)
        {
            reverseStr.push_back(str[index]);
        }

        if(reverseStr == str)
        {
            //cout<<"is palindrome!"<<endl;
            return true; 
        }
   
        else    
            return false;
    }
};

int main()
{
    Solution s ;
    int a = 12321;
    bool b = s.isPalindrome(a);
    cout<<"b:"<<b<<endl;
    return 0;

}