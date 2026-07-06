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
    void inorder(TreeNode* head,vector<int>& ans){
            if(head){
                inorder(head->left,ans);
                ans.push_back(head->val);
                inorder(head->right,ans);
            }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        inorder(root1,ans);
        inorder(root2,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};