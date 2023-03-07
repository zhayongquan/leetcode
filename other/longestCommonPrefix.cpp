//divide to solving 
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())
        {
            return "";
        }
        else{
            return lcp_divide( strs,0,strs.size()-1);
        }
    }

    string lcp_divide(const vector<string>& strs,int start,int end)
    {
        if(start == end )
        {
            return strs[start];
        }
        else{
            int mid = (start + end) /2;
            string left_lcp = lcp_divide(strs,start,mid);
            string right_lcp = lcp_divide(strs, mid+1 , end);
            return CommonPrefix(left_lcp , right_lcp);
        }
    }

    string CommonPrefix(const string &left_lcp , const string &right_lcp)
    {
        int minlength = min(left_lcp.size() ,right_lcp.size());
        for(int i=0; i<minlength; ++i)
        {
            if(left_lcp[i] != right_lcp[i] )
                return left_lcp.substr(0,i);
        }
        return left_lcp.substr(0,minlength);
    }
};

int main()
{
    Solution a;
    vector<string> b  = {"flower","flow","flight"};
    string d = a.longestCommonPrefix(b);
    cout<<"value is :"<<d<<endl;
    return 0;
}