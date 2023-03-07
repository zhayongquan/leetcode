#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
private:
    static constexpr int SEG_COUNT = 4;
    vector<string>ans;
    vector<int>segments;
public:
    void dfs(const string &s, int seg_id, int seg_begin){
        //找到4段ip，且遍历完字符串，得到一种结果
        if(seg_id == SEG_COUNT){
            if(seg_begin == s.size()){
                string segment_i;
                for(int i = 0; i < SEG_COUNT; i++){
                    //cout<<"segments[i]: "<<segments[i]<<endl;
                    segment_i += to_string(segments[i]);
                    if(i < SEG_COUNT -1){
                        segment_i += ".";
                    }
                }
                //cout<<"segment_i: "<<segment_i<<endl;
                ans.push_back(move(segment_i));
            }
            return;
        }
        //未遍历完，得到4段IP，退回。
        if(seg_begin == s.size()){
            return;
        }
        //前导0
        if(s[seg_begin] == '0'){
            segments[seg_id] = 0;
            dfs(s, seg_id + 1, seg_begin + 1);
        }
        //一般状况，接着遍历
        int Addr = 0;
        for(int seg_end = seg_begin; seg_end < s.size(); seg_end++){
            Addr = Addr * 10 + (s[seg_end] - '0');
            if(Addr > 0 && Addr <= 0xFF){
                //cout<<"Addr: "<<Addr<<endl;
                segments[seg_id] = Addr;
                dfs(s, seg_id + 1, seg_end + 1);
            }else{
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        segments.resize(SEG_COUNT);
        dfs(s,0,0);
        return ans;
    }
};

int main()
{
    Solution sol;
    string input = "101023";
    vector<string>output = sol.restoreIpAddresses(input);
    for(auto it = output.begin(); it != output.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}