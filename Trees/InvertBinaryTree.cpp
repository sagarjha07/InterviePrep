// lEETCODE 226

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL) return NULL;
        TreeNode* l=invertTree(root->left);
        TreeNode* r=invertTree(root->right);
        root->right=l;
        root->left=r;
        return root;
    }
};