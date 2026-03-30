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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        func(root, ans);
        return ans;
    }

    void func(TreeNode* root, vector<int>& ans) {
        //base case
        if(root == nullptr) return;

        //left
        func(root->left, ans);

        ans.push_back(root->val);
        //right
        func(root->right, ans);
    }
};