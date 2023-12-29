// LEETCODE 1448

class Solution {
public:
    void solve(TreeNode* root, int maxValInPath,int &ans){
        if(root==NULL) return;
        if(root->val>=maxValInPath) ans+=1;
        solve(root->left,max(maxValInPath,root->val),ans);
        solve(root->right,max(maxValInPath,root->val),ans);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int rootVal=root->val;
        int ans=0;
        solve(root,rootVal,ans);
        return ans;
    }
};