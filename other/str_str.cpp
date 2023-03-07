#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int ans = -1;
        if(m == 0 || n == 0 )
        {
            return ans;
        }
        else{
            for(int i = 0; i < n; i++)
            {
                if(haystack[i] == needle[0]){
                    //cout<<"haystack[i]:"<<haystack[i]<<endl;
                    //cout<<"needle[0]:"<<needle[0]<<endl;
                   int n_ptr = i;
                   //cout<<"n_ptr:"<<n_ptr<<endl;
                   string temp =  haystack.substr(n_ptr,m);
                   if(temp == needle)
                   {
                       ans = n_ptr;
                       return ans;
                   }
                } 
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    string a = "aaaaa";
    string b = "bba";
    int ret = sol.strStr(a,b);
    cout<<"ret: "<<ret<<endl;
    return 0;
}