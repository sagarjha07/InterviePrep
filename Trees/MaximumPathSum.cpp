// LEETCODE 124

class Solution {
public:
    int solve(TreeNode* root,int &ans){
        if(root==NULL) return 0;
        int leftSum=solve(root->left,ans);
        int rightSum=solve(root->right,ans);
        int temp = max(max(leftSum,rightSum)+root->val,root->val);
        ans=max({ans,temp,leftSum+rightSum+root->val});
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        if(root==NULL) return 0;
        int ans=INT_MIN;
        solve(root,ans);
        return ans;
    }
};