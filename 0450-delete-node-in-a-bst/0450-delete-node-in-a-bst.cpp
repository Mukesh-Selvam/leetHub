class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            if (!root->left) return root->right;
            if (!root->right) return root->left;
            
            TreeNode* minnode = findMin(root->right);
            root->val = minnode->val;
            root->right = deleteNode(root->right, minnode->val);
        }
        return root;
    }

    TreeNode* findMin(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }
};