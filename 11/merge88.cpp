#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){
            nums1 = nums2;
            return;
        }
        if(n == 0){
            return;
        }
        nums1.erase(nums1.begin() + m, nums1.end());
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
    }
};

int main()
{
    vector<int>n1 = {1,2,3,0,0,0};
    vector<int>n2 = {2,5,6};
    int m = 3, n = 3;
    Solution sol;
    sol.merge(n1,m,n2,n);
    for(vector<int>::iterator it = n1.begin(); it != n1.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}