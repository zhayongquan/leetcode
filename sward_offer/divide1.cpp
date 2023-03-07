#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    int divide(int a, int b) {          //a/b
        int abs_a = abs(a);
        int abs_b = abs(b);
        int loop = abs_b;
        int ans = 1;
        int reaminder = abs_a;
        if((a == 0 || b == 0) || (abs_a < abs_b) ){
            return 0;
        }
        while(abs(reaminder) > abs(loop)){
            abs_b += loop;
            reaminder = abs_a - abs_b;
            ans++;
        }
        if(signbit(a) != signbit (b)){
            ans = -ans;
        }
        return ans;
    }
};


int main()
{
    Solution sol;
    int ret = sol.divide(-2147483648,-1);
    cout<<"ret:"<<ret<<endl;
    return 0;
}