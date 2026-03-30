class Solution {
public:
    unordered_map<int,int> map;
    int index = 0;

    TreeNode* makeTree(int left, int right, vector<int>& preorder) {
        if (left > right) return nullptr;

        int value = preorder[index++];
        TreeNode* root = new TreeNode(value);

        int mid = map[value];

        root->left = makeTree(left, mid - 1, preorder);
        root->right = makeTree(mid + 1, right, preorder);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index = 0;
        map.clear();

        for (int i = 0; i < inorder.size(); i++) {
            map[inorder[i]] = i;
        }

        return makeTree(0, inorder.size() - 1, preorder);
    }
};