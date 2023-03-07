#include<iostream>
#include<vector>
using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    void preorder(TreeNode* root,vector<int>&ret){
        if(root == nullptr){
            return;
        }
        ret.push_back(root->val);
        preorder(root->left,ret);
        preorder(root->right,ret);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        preorder(root,ans);
        return ans;
    }
};

int main()
{
  Solution sol;
  TreeNode root1(1);
  TreeNode root2(2);
  TreeNode root3(3);
  root1.right = &root2;
  root2.left = &root3;
  
  vector<int>ret = sol.preorderTraversal(&root1);
  for(vector<int>::iterator it = ret.begin(); it !=ret.end(); it++ )
  {
    cout<<*it<<" ";
  }
  cout<<endl;
  return 0;
    
}