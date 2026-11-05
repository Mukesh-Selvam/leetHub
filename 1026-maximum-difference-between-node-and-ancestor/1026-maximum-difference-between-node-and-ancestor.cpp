class Solution {
private:
    int dfs(TreeNode* node, int curMin, int curMax) {
        if (!node) return curMax - curMin;
        
        curMin = min(curMin, node->val);
        curMax = max(curMax, node->val);
        
        int leftDiff = dfs(node->left, curMin, curMax);
        int rightDiff = dfs(node->right, curMin, curMax);
        
        return max(leftDiff, rightDiff);
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};