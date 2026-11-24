class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if (!root) {
            return -1;
        }
        long ans = dfs(root, root->val);
        return ans == LONG_MAX ? -1 : static_cast<int>(ans);
    }

private:
    long dfs(TreeNode* node, int minVal) {
        if (!node) {
            return LONG_MAX;
        }
        if (node->val > minVal) {
            return node->val;
        }
        return min(dfs(node->left, minVal), dfs(node->right, minVal));
    }
};