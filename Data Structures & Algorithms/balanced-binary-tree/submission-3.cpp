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
        
        return dfs(root) != -1;

    }
    int dfs(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int l = dfs(root->left);
        int r = dfs(root->right);
        int hold = abs(l-r);
        /*if(l == -1 || r == -1){
            return -1;
        }else*/ if(hold > 1){
            return -1;
        }else {
            return 1 + max(l,r);
        }

    }
};
