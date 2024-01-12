// LEETCODE 99

class Solution {
public:
    TreeNode*first;
    TreeNode*second;
    TreeNode*prev;
    void solve(TreeNode*root){
        if(root==NULL) return;
        solve(root->left);
        if(prev!=NULL){
            if(first==NULL && prev->val>=root->val){
                first=prev;
                second=root;
            }
            if(first!=NULL && prev->val>=root->val){
                second=root;
            }
        }
        prev=root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=NULL;
        second=NULL;
        prev=NULL;
        solve(root);
        swap(first->val,second->val);
    }
};