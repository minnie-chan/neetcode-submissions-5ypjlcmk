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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vc;
        func(root, vc);
        return vc;
    }
        void func(TreeNode* root, vector<int>& vc){
            if(root == nullptr){
                return;
            }
                //left
            func(root->left, vc);
                //right
            func(root->right,vc);
            vc.push_back(root->val);
        }
};