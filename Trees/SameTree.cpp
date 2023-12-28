// LEETCODE 100

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL)
            return false;
        if (q == NULL)
            return false;
        bool isLeftTreeSame = isSameTree(p->left, q->left);
        bool isRightTreeSame = isSameTree(p->right, q->right);
        return p->val == q->val && isLeftTreeSame && isRightTreeSame;
    }
};