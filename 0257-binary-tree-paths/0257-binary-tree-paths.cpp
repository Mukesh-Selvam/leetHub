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

    vector<string> binaryTreePaths(TreeNode* root) {
        string temp="";
        vector<string>ans;
        solve(root,ans,temp);
        return ans;
    }
    void solve(TreeNode* root,vector<string>& ans,string temp){
        if(root && !root->left && !root->right){
            string s=to_string(root->val);
            temp+=s;
            ans.push_back(temp);
            return;
        }
        if(root && root->left && !root->right){
            string s=to_string(root->val);
            temp=temp+s+"->";
            solve(root->left,ans,temp);
            return;
        }
        if(root && !root->left && root->right){
            string s=to_string(root->val);
            temp=temp+s+"->";
            solve(root->right,ans,temp);
            return;
        }
        string s=to_string(root->val);
        temp=temp+s+"->";
        solve(root->left,ans,temp);
        solve(root->right,ans,temp);

    }
};