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
    pair<int,int> dfs(TreeNode* node) {
        if (node == nullptr)
            return pair<int,int>(0, 0);

        pair<int,int> left = dfs(node->left);
        pair<int,int> right = dfs(node->right);

        int ltake = left.first;
        int lskip = left.second;

        int rtake = right.first;
        int rskip = right.second;

        int take = node->val + lskip + rskip;
        int skip = max(ltake, lskip) + max(rtake, rskip);

        return pair<int,int>(take, skip);
    }

    int rob(TreeNode* root) {
        pair<int,int> result = dfs(root);
        return max(result.first, result.second);
    }
};