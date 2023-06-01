#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string>>ans;
    vector<vector<int>>f;
    vector<string>tmp;
    int n;
    void dfs(int cur, string &s){
        if(cur == n){
            ans.push_back(tmp);
            return;
        }
        for(int i = cur; i < n; ++i){
            if(f[cur][i]){
                tmp.push_back(s.substr(cur, i - cur + 1));
                dfs(i + 1, s);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.size();
        f.assign(n,vector<int>(n,true));
        for(int i = n-1; i >= 0; --i){
            for(int j = i + 1; j < n; ++j){
                f[i][j] = (s[i] == s[j]) && f[i + 1][ j- 1];
            }
        }
        dfs(0,s);
        return ans;
    }
};

// class Solution {
// private:
//     vector<vector<int>> f;
//     vector<vector<string>> ret;
//     vector<string> ans;
//     int n;

// public:
//     void dfs(const string& s, int i) {
//         if (i == n) {
//             ret.push_back(ans);
//             return;
//         }
//         for (int j = i; j < n; ++j) {
//             if (f[i][j]) {
//                 ans.push_back(s.substr(i, j - i + 1));
//                 dfs(s, j + 1);
//                 ans.pop_back();
//             }
//         }
//     }

//     vector<vector<string>> partition(string s) {
//         n = s.size();
//         f.assign(n, vector<int>(n, true));

//         for (int i = n - 1; i >= 0; --i) {
//             for (int j = i + 1; j < n; ++j) {
//                 f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
//             }
//         }

//         dfs(s, 0);
//         return ret;
//     }
// };


int main(){
    Solution sol;
    string input = "aaba";
    vector<vector<string>>output = sol.partition(input);
    for(auto it = output.begin(); it != output.end(); it++){
        for(auto jt = (*it).begin(); jt != (*it).end(); jt++){
            cout<<*jt<<" ";
        }
        cout<<endl;
    }
    return 0;
}