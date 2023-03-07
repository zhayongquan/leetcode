#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // int n = height.size();
        // int end_num = height.back();
        // int start,end;
        // int area = 0;
        // for(int i = 0; i < n; i++)
        // {
        //     for(int j = i + 1; j < n;)
        //     {
        //         if(height[j] < end_num )
        //         {
        //             j++;
        //         }
        //         else{
        //             if((j-i) * min(height[i],height[j]) > area)
        //             {
        //                 area = (j-i) * min(height[i],height[j]);
        //             }
        //             else{
        //                 j++;
        //             }
                    
        //         }
        //     }
        // }
        // return area;
        int l = 0;
        int n = height.size();
        int r = n - 1;
        int ans = 0;
        while(l < r)
        {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(area, ans);
            if(height[l] <= height[r])
            {
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> demo =  {1,8,6,2,5,4,8,3,7};
    int ret = sol.maxArea(demo);
    cout<<"ret :"<<ret<<endl;
    return 0;
}

// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int l = 0, r = height.size() - 1;
//         int ans = 0;
//         while (l < r) {
//             int area = min(height[l], height[r]) * (r - l);
//             ans = max(ans, area);
//             if (height[l] <= height[r]) {
//                 ++l;
//             }
//             else {
//                 --r;
//             }
//         }
//         return ans;
//     }
// };

