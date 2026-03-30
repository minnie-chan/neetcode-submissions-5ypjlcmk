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
    int maxDepth(TreeNode* root) {
     int ans = 0;
     dfs(root,ans);
     return ans;
    }
    int dfs(TreeNode* root, int& ans){
        if(root == nullptr){
            return 0;
        }

        int lefts = dfs(root->left, ans);
        int rights = dfs(root->right, ans);

        ans = 1 + max( lefts, rights);
        return ans;
    }
};
