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
    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int ans = 0;
        dfs(root,k,count,ans);
        return ans;

    }
    void dfs(TreeNode* root, int k, int& count, int& ans) {
        // base case
        if(root == nullptr){
            return;
        }

        // left
        dfs(root->left,k,count,ans);
        // visit current
        count++;
        if(count == k){
            ans = root->val;
        }
        // right
        dfs(root->right,k,count,ans);
    }
};
