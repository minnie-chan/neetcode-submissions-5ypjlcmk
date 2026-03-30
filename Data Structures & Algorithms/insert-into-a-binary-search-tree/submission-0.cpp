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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            return new TreeNode(val);
        }
        if(val > root->val){
            TreeNode* temp = insertIntoBST(root->right, val);
            root->right = temp;
        } else if(val < root->val){
            TreeNode* temps = insertIntoBST(root->left, val);
            root->left = temps;
        }
        return root;
    }
};