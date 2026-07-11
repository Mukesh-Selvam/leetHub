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
    int count=0;
    int val=0;
    int tn=0;
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        count++;
        val+=(root->val);
        inorder(root->right);
    }
    int averageOfSubtree(TreeNode* root) {
        if( !root) return 0;
        count=0;
        val=0;
        inorder(root);
        if(val/count==root->val){
            tn++;
        }
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return tn;
    }
};