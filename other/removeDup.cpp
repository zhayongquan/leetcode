#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        for(vector<int>::iterator it = nums.begin(); it+1 != nums.end();)
        {
            cout<<"start"<<endl;
            if(n == 1)
            {
                return n;
            }
            if(*it != *(it+1))
            {
                it++;
            }
            else{
                nums.erase(it + 1);
            }
            cout<<"end "<<endl;
        }
        return nums.size();
    }
};

int main()
{
    Solution sol;
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(2);
    // v1.push_back(2);
    // v1.push_back(3);
    // v1.push_back(3);
    // v1.push_back(3);
    int ret = sol.removeDuplicates(v1);
    cout<<"ret: "<<ret<<endl;
    return 0;
}