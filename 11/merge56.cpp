#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(intervals.size() == 0){
            return{};
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merged;
        for(int i = 0; i < n; i++){
            int L = intervals[i][0], R = intervals[i][1];
            if(!merged.size() || merged.back()[1] < L){
               merged.push_back({L,R});
            }
            else{
                merged.back()[1] = max(merged.back()[1],R);
            }
        }
        return merged;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> input = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ret = sol.merge(input);
    for(vector<vector<int>>::iterator it = ret.begin();it!=ret.end();it++)
    {
        for(vector<int>::iterator jt = (*it).begin(); jt!= (*it).end(); jt++)
        {
            cout<<*jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}