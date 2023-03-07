#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main()
{
    vector<int>input {1,2,3,4,5,6,7,8,9};
    int start = 1,end = 4;
    int val = accumulate(input.begin()+start,input.begin()+(end-start),0);
    cout<<val<<endl;
    return 0;
}