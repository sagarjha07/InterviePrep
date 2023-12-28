// LEETCODE 199

class Solution {
public:
    void solve(TreeNode* root, int h, int &mx, vector<int>&ans){
        if(root==NULL) return;
        if(h>mx){
            ans.push_back(root->val);
            mx=h;
        }
        solve(root->right,h+1,mx,ans);
        solve(root->left,h+1,mx,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        int mx=-1;
        solve(root,0,mx,ans);
        return ans;
    }
};