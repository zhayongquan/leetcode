#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

int main(){
    vector<int>nums{2,3,3,4,3};
    unordered_map<int,int>counts;
    int majority = 0, cnt = 0;
    for (int num: nums) {
            counts[num];
            counts[num] = num;

            // if (counts[num] > cnt) {
            //     majority = num;
            //     cnt = counts[num];
            // }
        }
    counts[2] = 200;
    for(auto it  = counts.begin(); it != counts.end(); it++){
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}