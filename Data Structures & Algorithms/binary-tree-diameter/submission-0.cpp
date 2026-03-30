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
    int diameterOfBinaryTree(TreeNode* root) {
        int zz = 0;
        func(root,zz);
        return zz;
    }
    int func(TreeNode* root, int& zz){
        if(root == nullptr){
            return 0;
        }

        int leftDepth = func(root->left,zz);

        int rightDepth = func(root->right,zz);

        int mx = 1 + max(leftDepth, rightDepth);
        zz = max(zz, leftDepth + rightDepth); 
        return mx;
    }
};
