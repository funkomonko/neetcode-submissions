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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        else if(root->val == subRoot->val){
            return check(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
        else{
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
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
