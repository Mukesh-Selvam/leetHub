class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return add(root,1,val,depth);   
    }
    TreeNode* add(TreeNode* root,int cd,int val,int depth){
        if(root==NULL) return NULL;
        if(depth==1){
            TreeNode* nn=new TreeNode(val);
            nn->left=root;
            return nn;
        }
        if(cd==depth-1){
            TreeNode* a=new TreeNode(val); 
            TreeNode* b=new TreeNode(val);
            TreeNode* oll=root->left;
            TreeNode* olr=root->right;
            root->left=a;
            root->right=b;
            a->left=oll;
            b->right=olr;
            return root;
        }
        add(root->left,cd+1,val,depth);
        add(root->right,cd+1,val,depth);
        return root;
    }
};
