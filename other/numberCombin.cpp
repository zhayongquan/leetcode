#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;



class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.empty())
        {
            return ans;
        }
        unordered_map<char , string>phoneMap{
             {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        string combine;
        backtrace(ans,phoneMap,digits,combine,0);
        return ans;
    }

void backtrace(vector<string>& ans,const unordered_map<char, string>& phoneMap,const string& digits,string& combine, int index )
{
    //cout<<"digits.length:"<<digits.length()<<endl;
    //cout<<"length:"<<digits.length()<<endl;
    if(index == digits.length())
    {
        ans.push_back(combine);
    }
    else{
        char digit = digits[index];
        const string & letters = phoneMap.at(digit);
        for(const char& letter : letters)
        {
            combine.push_back(letter);
            backtrace(ans,phoneMap,digits,combine,index + 1);
            combine.pop_back();
        }
    }
}

};



int main()
{   
    Solution sol;
    vector<string>ret = sol.letterCombinations("23");
    for(vector<string>::iterator it = ret.begin(); it != ret.end(); it++)
    {
        cout<<*it<<endl;
    }
    return 0;
}

