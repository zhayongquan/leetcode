#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Tnode{
    string data;
    struct Tnode *fir, *sib;   //fir 指向子节点，sib指向兄弟节点  
};

class Solution{
public: 
    Tnode* ChangeTree(vector<vector<string>>&input){
        Tnode* Tree = (Tnode*)malloc(sizeof(Tnode));      //二叉树的父节点
        Tnode* bitTree = NULL;
        //初始父节点为空，左子树为第一个子节点（省份信息），右子树为兄弟节点，故为空
        Tree->fir = bitTree;
        Tree->sib = NULL;
        Tree->data = "";
        if(bitTree == NULL){
            bitTree = (Tnode*)malloc(sizeof(Tnode));
        }
    }

};

int main()
{
    Solution sol;
    vector<vector<string>>input{{"henan","henan","henan","hebei","hebei"},{"zz","zz","xx","sjz","lf"},{"1","2","3","4","5"}};
    Tnode* output = sol.ChangeTree(input);
}