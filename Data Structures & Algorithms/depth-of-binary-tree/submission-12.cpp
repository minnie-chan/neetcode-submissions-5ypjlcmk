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
        if(root == nullptr){
            return 0;
        }
        queue<TreeNode*> qu;
        qu.push(root);
        int ans = 0;
        while(qu.empty() == false){
            int size = qu.size();

            for(int i = 0; i < size;i++){
                auto x = qu.front();
                qu.pop();
                if(x->left != nullptr){
                    qu.push(x->left);
                }
                if(x->right != nullptr){
                    qu.push(x->right);
                }

            }
            ans++;
        }
        return ans;
    }
};
