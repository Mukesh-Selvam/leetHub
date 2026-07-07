class Solution {
private:
    long long ts=0;
    long long mp=0;
    const int MOD=1e9+7;
    int TotalSum(TreeNode* root) {
        if (!root) return 0;
        return root->val+TotalSum(root->left)+TotalSum(root->right);
    }
    int findMax(TreeNode* root) {
        if (!root) return 0;
        long long cs=root->val+findMax(root->left)+findMax(root->right);
        long long cp=cs*(ts-cs);      
        mp=max(mp,cp);
        return cs;
    }
public:
    int maxProduct(TreeNode* root) {
        ts =TotalSum(root);
        findMax(root);
        return mp%MOD;
    }
};