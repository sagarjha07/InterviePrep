// LEETCODE 98

class Solution {
public:
    bool isValidBST(TreeNode* root, long mn = LONG_MIN, long mx = LONG_MAX) {
        if (root == NULL)
            return true;
        bool leftIsBst = isValidBST(root->left, mn, root->val);
        bool rightIsBst = isValidBST(root->right, root->val, mx);
        if (root->val > mn && root->val < mx && leftIsBst && rightIsBst) {
            return true;
        }
        return false;
    }
};