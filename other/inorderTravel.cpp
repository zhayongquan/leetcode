#include<iostream>
#include<vector>
#include<string>

using namespace std;

  //Definition for a binary tree node.
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
    void inorder(TreeNode* root, vector<int>& res)
    {
        if(!root){
          //cout<<"!root:"<<!root<<endl;
          return;
        }
        inorder(root->left,res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
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
  
  vector<int> ret = sol.inorderTraversal(&root1);
  for(vector<int>::iterator it = ret.begin(); it !=ret.end(); it++ )
  {
    cout<<*it<<" ";
  }
  cout<<endl;
  return 0;
}