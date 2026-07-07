
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int l=maxDepth(root->left);
        int r=maxDepth(root->right);
        if(!root->left) return r+1;
        if(!root->right) return l+1;
        return max(l,r)+1;
    }
};