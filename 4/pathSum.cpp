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
    vector<vector<int>>ans;
    vector<int>path;
    void dfs(TreeNode* root, int targetSum){
        if(root == nullptr){
            return;
        }
        path.push_back(root->val);
        targetSum = targetSum - root->val;
        if((root->left == nullptr && root->right == nullptr) && targetSum == 0){
            ans.push_back(path);
        }
        dfs(root->left,targetSum);
        dfs(root->right,targetSum);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return ans;
    }
};