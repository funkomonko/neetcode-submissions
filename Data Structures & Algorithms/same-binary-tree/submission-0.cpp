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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);
    }

private:
    bool check(TreeNode* root, TreeNode* root1){
        if(!root && !root1) return true;
        else if(root && root1){
            if(root->val == root1->val) return check(root->left, root1->left) && check(root->right, root1->right);
            else return false;
        }
        else{
            return false;
        }
    }
};
