#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        while(m < n){    //补全字符串，两者相等
            a = '0' + a;
            m++;
        }
        while(n < m){
            b = '0' + b;
            n++;
        }
        int carry = 0;
        for(int i = m - 1; i >= 0; i--){
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            a[i] = (sum) % 2 + '0';
            carry = sum/2;
            cout<<"carry:"<<carry<<endl;
        }
        if(carry > 0){
            a = '1' + a;
        }
        return a;
    }
};

// class Solution {
// public:
// 	string addBinary(string a, string b) 
// 	{
// 		int asize = a.size(), bsize = b.size();
// 		while (asize > bsize)//补齐
// 		{
// 			b = '0' + b;
// 			bsize++;
// 		}
// 		while (asize < bsize)
// 		{
// 			a = '0' + a;
// 			asize++;
// 		}
// 		int carry = 0;  //进位
// 		for (int i = asize - 1; i >= 0; i--)
// 		{
// 			int sum = a[i] - '0' + b[i] - '0' + carry;
// 			a[i] = (sum) % 2+'0';//本位数值
// 			carry = sum / 2;//进位更新
// 		}
// 		if (carry > 0)//有溢出
// 			a = '1' + a;
// 		return a;
// 	}
// };

int main()
{
    Solution sol;
    string a = "0";
    string b = "0";
    string ret = sol.addBinary(a,b);
    cout<<"ret: "<<ret<<endl;
    return 0;
}