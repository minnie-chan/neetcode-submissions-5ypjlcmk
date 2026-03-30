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
    TreeNode* deleteNode(TreeNode* root, int key) {
        return func(root,key);
            

    }
    TreeNode* func(TreeNode* root, int& key){
        if(root == nullptr){
            return 0;
        }
        if(key < root->val){
           root->left = func(root->left, key);
        } else if(key > root->val){
            root->right =  func(root->right, key);
        } else if(root->val == key){
            if(root->left == nullptr && root->right == nullptr){
                return nullptr;                
            } else if(root->left != nullptr && root->right != nullptr){
                    TreeNode* temp = root->right;
                while (temp->left) temp = temp->left; // find min on right side
                root->val = temp->val;    // copy the successor value
                root->right = func(root->right, temp->val); // delete the duplicate
                return root;

            } else if(root->right != nullptr){
                    return root ->right;
            } else if(root->left != nullptr){
                    return root ->left; 
            }
        }
        return root;
    }
};