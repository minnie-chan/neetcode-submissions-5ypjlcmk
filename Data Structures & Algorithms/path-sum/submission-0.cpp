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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return dfs(root,targetSum);
        
    }
    bool dfs(TreeNode* root, int targetsum){
        if (root == nullptr) {
            return false;
        }
        targetsum -= root->val;

        if(root->left == nullptr && root->right == nullptr){
            if(targetsum == 0){
                return true;
            } else {
                return false;
            }
        }
        return dfs(root->left, targetsum) || dfs(root->right, targetsum);
    }
};