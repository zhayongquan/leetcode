#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0){
            return {};
        }
        vector<vector<int>> ans;
        int p = 0;
        while(p < n && intervals[p][1] < newInterval[0]){
            ans.push_back(intervals[p]);
            p++;
        }
        while(p < n && intervals[p][0] <= newInterval[1]){
            newInterval[0] = min(intervals[p][0],newInterval[0]);
            newInterval[1] = max(intervals[p][1],newInterval[1]);
            p++;
        }
        ans.push_back(newInterval);
        while(p < n && intervals[p][0] > newInterval[1]){
            ans.push_back(intervals[p]);
            p++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>>input{{1,3},{6,9}};
    vector<int>area {2,5};
    vector<vector<int>>output = sol.insert(input,area);
    for(vector<vector<int>>::iterator it = output.begin();it!= output.end();it++){
        for(vector<int>::iterator jt = (*it).begin(); jt!=(*it).end();jt++){
            cout<<*jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}