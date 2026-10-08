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

        dfs(root,0,ans);
        return ans;

    }
    int dfs(TreeNode* root, int depth,  int& ans){
        
        TreeNode* curr = root;
        if(curr == nullptr){
            return 0 ;
        }

        int l = dfs(curr->left,depth,ans);

        int r = dfs(curr->right,depth,ans);

        depth = 1 + max(l,r);
        ans = max(ans,depth);
        return depth;   
    }
};
