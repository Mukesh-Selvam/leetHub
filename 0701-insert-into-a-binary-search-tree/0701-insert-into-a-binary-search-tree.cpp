class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* nn=new TreeNode(val);
        if(root==NULL){
            root=nn;
            return root;
        }
        TreeNode* temp=root;
        while(1){
                if(val<=root->val){
                    if(!root->left){
                        root->left=nn;
                        break;
                    }else{
                        root=root->left;
                    }
                }else{
                    if(!root->right){
                        root->right=nn;
                        break;
                    }else{
                        root=root->right;
                    }
                }
        }
        return temp;
    }
};