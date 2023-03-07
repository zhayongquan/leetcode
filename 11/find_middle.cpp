#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans;
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        int n = nums1.size();
        //cout<<"n:"<<n<<endl;
        if(n%2 == 0){      //e.g  n=8, middle is 3 and 4;
            ans = (nums1[n/2 - 1] + nums1[n/2]) / 2.0; 
            //cout<<"ans:"<<ans<<endl;
        }
        else{
            ans = nums1[n/2];
        }
        return ans;
    }
};

int main()
{   
    vector<int>v1 = {1,2};
    vector<int>v2 = {3,4};
    Solution sol;
    double ret = sol.findMedianSortedArrays(v1,v2);
    cout<<"ret:"<<ret<<endl; 
    return 0;
}