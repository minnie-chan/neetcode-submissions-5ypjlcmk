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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == nullptr){
            return result;
        }
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int woof = q.size();
            vector<int> level;

            for(int i = 0; i < woof; i++){
                TreeNode* s = q.front();    
                q.pop();
                level.push_back(s->val);

                if(s->left != nullptr){
                    q.push(s->left);
                }
                if(s->right != nullptr){
                    q.push(s->right);
                }
            }
            result.push_back(level);
        }
        return result;
    }
};
