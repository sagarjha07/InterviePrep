// LEETCODE 102

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> v;
            for(int i=0;i<n;i++){
                TreeNode* f= q.front();
                q.pop();
                v.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};