#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>

using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n %2 == 1)
            return false;
        
        unordered_map<char,char> bracket = {        
            {')','('},
            {']','['},
            {'}','{'}
        };

        stack<char> stk;
        for(char ch : s)  
        {
            if(bracket.count(ch))  
            {  
                if(stk.empty() || stk.top() != bracket[ch])
                {   
                    //cout<<"start!"<<endl;
                    return false ;
                    //cout<<"end!"<<endl;
                }
                stk.pop();
            }
            else{         
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};

int main()
{
    Solution s;
    string a = "()[]{}";
    bool b = s.isValid(a);
    cout<<"b:"<<b<<endl;
    return 0;
}