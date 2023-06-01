
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    void test(map<string,int>&m1,string ref){
        if(m1.find(ref) == m1.end()){
            cout<<"not store!"<<endl;
        }
    }
};

int main(){
    map<string,int>input = {{"a",1}, {"b", 2}, {"c", 3}, {"d", 4}};
    Solution sol;
    string test = "e";
    sol.test(input,test);
    return 0;
}