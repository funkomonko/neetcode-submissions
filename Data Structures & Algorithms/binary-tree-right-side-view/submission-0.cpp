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
    vector<int> rightSideView(TreeNode* root) {
        queue <TreeNode*> next;
        vector<int> out;

        if (root == nullptr) {
            return out;
        }
        
        next.push(root);
        while(!next.empty()){
            int leng = next.size();
            for(int i =0 ; i<leng; i++){
                auto t = next.front();
                if(i == leng - 1 && t){
                    out.push_back(t->val);
                }
                if (t->left != nullptr) {
                    next.push(t->left);
                }
                if (t->right != nullptr) {
                    next.push(t->right);
                }
                next.pop();
            }
        }

        return out;
    }
};
