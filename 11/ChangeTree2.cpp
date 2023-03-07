#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Tnode{
    string data;
    struct Tnode *fir, *sec, *thi, *fou, *fif;   //五个指针指向五个节点 
};

class Solution{
public: 
    Tnode* ChangeTree(vector<vector<string>>&input){
        Tnode* Tree = (Tnode*)malloc(sizeof(Tnode));      //二叉树的父节点
        Tree->data = "";
        for(vector<vector<string>>::iterator it = input.begin();it!=input.end();++it){
            for(vector<string>::iterator jt = (*it).begin();jt!=(*it).end();++jt){
                
            }
        }
    }

};

int main()
{
    Solution sol;
    vector<vector<string>>input{{"henan","henan","henan","hebei","hebei"},{"zz","zz","xx","sjz","lf"},{"1","2","3","4","5"}};
    
}