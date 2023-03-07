#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int flag = 0;
        if(digits[n-1] < 9){
            digits[n-1]++;
            return digits;
        }
        else if(digits[n-1] == 9){          //last is 9
            digits[n-1] = 0;
            for(int i = n-2; i >= 0; i--){
                if(digits[i] == 9){
                    digits[i] = 0;
                    flag++;
                }
                else if(digits[i] != 9){
                    digits[i]++;
                    return digits;
                }
            }
            if(flag == n-1){           //all is 9
                digits.insert(digits.begin(),1);
            }
        }
        return digits;
    }
};


int main()
{
    Solution sol;
    vector<int>input = {0};
    vector<int>output = sol.plusOne(input);
    for(vector<int>::iterator it = output.begin(); it!=output.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
    return 0;
}