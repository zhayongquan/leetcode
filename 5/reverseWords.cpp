#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        stack<string>s1;
        string tmp;
        int idx = 0;
        for(int start = 0; start < len; ++start){
            if(s[start] != ' '){
                //填空白符，将idx移动到下一个单词开头位置
                //if(idx != 0) s[idx] = ' ';
                //循环遍历至单词末尾
                int end = start;
                while(end < len && s[end] != ' ') {
                    end++;
                }
                //cout<<"start:"<<start<<" end:"<<end<<endl;
                tmp = s.substr(start,end-start);
                //cout<<"tmp:"<<tmp<<endl;

                //入栈
                s1.push(tmp);
                s1.push(" ");

                //更新start，找下一个单词
                start = end;
            }
        }
        if(!s1.empty()){
            //弹出栈顶的空格符
            s1.pop();
        }
        string ans = "";
        while(!s1.empty()){
            ans += s1.top();
            s1.pop();
        }
        return ans;
    }
};

int main(){
    Solution sol;
    string input = "the sky is blue";
    string ret = sol.reverseWords(input);
    cout<<"ret:"<<ret<<endl;
    return 0;
}