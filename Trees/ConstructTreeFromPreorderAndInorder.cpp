// LEETCODE 105

class Solution {
public:
    TreeNode* build(int s, int e, int& ind, vector<int>& pre, vector<int>& in) {
        if (s > e)
            return NULL;
        TreeNode* root = new TreeNode(pre[ind]);
        int k = -1;
        for (int j = s; j <= e; j++) {
            if (in[j] == pre[ind]) {
                k = j;
                break;
            }
        }
        ind++;
        root->left = build(s, k - 1, ind, pre, in);
        root->right = build(k + 1, e, ind, pre, in);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
            return NULL;
        int n = preorder.size();
        int s = 0;
        int e = n - 1;
        int ind = 0;
        return build(s, e, ind, preorder, inorder);
    }
};