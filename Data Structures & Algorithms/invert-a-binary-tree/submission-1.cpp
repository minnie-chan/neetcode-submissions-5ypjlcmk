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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr ){ 
            return nullptr;
        }

        TreeNode* lefts = root -> left;
        TreeNode* rights = root -> right;

        root -> left = rights;
        root -> right = lefts;

        invertTree(root -> left);
        invertTree(root -> right);
        
        return root;
    }
};
