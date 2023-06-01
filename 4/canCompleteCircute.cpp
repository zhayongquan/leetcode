#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += gas[i] - cost[i];
        }
        if(sum < 0){
            return -1;
        }
        int tank = 0;
        int start = 0;
        for(int i = 0; i < n; i++){
            tank += gas[i] - cost[i];
            if(tank < 0){
                tank = 0;
                start = i + 1;
            }
        } 
        return start == n ? n : start;
    }
};

int main(){
    vector<int>gas{1,2,3,4,5};
    vector<int>cost{3,4,5,1,2};
    Solution sol;
    int ans = sol.canCompleteCircuit(gas,cost);
    cout<<"ans : "<<ans<<endl;
    return 0;
}