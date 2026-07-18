/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return check(root->val, root);
    }

private: 
    int check(int maxV, TreeNode* root){
      if(!root) return 0;

      int res = (root->val >= maxV) ? 1 : 0;
      maxV = max(maxV, root->val);
      res += check(maxV, root->left);
      res += check(maxV, root->right);
      return res;  
    } 
};
