class Solution {
public:
    long tot = 0;
    int ans = INT_MIN;

    void sum(TreeNode* root) {
        if (!root) return;
        tot += (root->val);
        sum(root->left);
        sum(root->right);
    }

    int maxPathSum(TreeNode* root) {
        if (!root) return ans;
        calculateMaxPath(root);
        return ans;
    }

private:
    int calculateMaxPath(TreeNode* root) {
        if (!root) return 0;
        int left_gain = max(calculateMaxPath(root->left), 0);
        int right_gain = max(calculateMaxPath(root->right), 0);
        int current_path_sum = root->val + left_gain + right_gain;
        ans = max(ans, current_path_sum);

        return root->val + max(left_gain, right_gain);
    }
};