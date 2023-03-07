#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int num = 0;
        for(vector<int>::iterator it = nums.begin(); it != nums.end(); )
        {   
            
            if((*it) == val)
            { 
                nums.erase(it);
                
            }
            else{
                it++;
            }
        }
        return nums.size();
    }
};


int main()
{
    Solution s;
    vector<int>v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    int val = 3;
    int sol = s.removeElement(v,val);
    cout<<"solution is :"<<sol<<endl;
    return 0;
}