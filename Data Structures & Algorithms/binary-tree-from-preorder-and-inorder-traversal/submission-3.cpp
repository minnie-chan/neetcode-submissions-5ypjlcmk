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
    unordered_map<int,int> mp;
    int track = 0;
    TreeNode* travel(int left, int right, vector<int>& preorder){
        if(left > right){
            return nullptr;
        }
        int s = preorder[track++];
        TreeNode* root = new TreeNode(s);
        
        int mid = mp[s];//*

        root->left = travel(left, mid - 1, preorder);// just ne a refrshe on what this does 
        root->right = travel(mid + 1, right, preorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mp.clear();
        track = 0;
        for(int i = 0; i < (int)inorder.size(); i++){
            mp[inorder[i]] = i;
        }

        return travel(0,inorder.size() -1, preorder);
    }
};
