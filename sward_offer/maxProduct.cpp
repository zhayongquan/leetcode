#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int>mask(n);            //每个words创立一个mask，用来求是否有重复元素
        for(int i = 0; i < n; i++){
            string word;
            word = words[i];
            for(int j = 0; j < word.size(); j++){
                mask[i] |= 1 << (word[j] - 'a');
            }
        }
        int max_sum  = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if((mask[i] & mask[j]) == 0){
                    int mul = int(words[i].length() * words[j].length());
                    max_sum = max(mul,max_sum);
                }
            }
        } 
        return max_sum;
    }
};

int main()
{
    Solution sol;
    vector<string>input{"a","ab","abc","d","de"};
    int ret = sol.maxProduct(input);
    cout<<"ret:"<<ret<<endl;
    return 0;
}