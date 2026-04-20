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
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(root == nullptr){
            return false;
        }
        if
    }
    bool func(TreeNode* root, TreeNode* subroot){
        if(root == nullptr && subroot == nullptr){
            return true;
        } else if(root == nullptr || subroot == nullptr){
            return false; 
        } else if( root->val != subroot->val){
            return false;
        }

        return(func(root->left, subroot->left) && func(root->right, subroot->right))
    }
};
