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
    bool isBalanced(TreeNode* root) {
        
        return func(root) != -1;
    }
    int func(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int leftdepth = func(root->left);
        
        int rightdepth = func(root->right);
        
        if(abs(leftdepth - rightdepth) > 1){
            return -1;
        } 
        return 1 + max(leftdepth, rightdepth);
        
    }
};
