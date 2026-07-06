class Solution {
public:
    TreeNode* swap(TreeNode* root){
        if (root==NULL){
            return 0;
        }
        TreeNode* temp=root->left;
        root->left=root->right;
        root->right=temp;
        swap(root->left);
        swap(root->right);
        return root;
    }
    TreeNode* invertTree(TreeNode* root) {
        swap(root); 
        return root;
    }
};