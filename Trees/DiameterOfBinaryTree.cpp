// LEETCODE 543

class Solution {
public:
    int solve(TreeNode*root, int&ans){
        if(root==NULL) return 0;
        int ld=solve(root->left,ans);
        int rd=solve(root->right,ans);
        int temp=max(ld,rd)+1;
        ans=max({ans,temp,ld+rd+1});
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=0;
        solve(root,ans);
        return ans-1;
    }
};