// LEETCODE 572

class Solution {
public:
    bool identical(TreeNode*t,TreeNode*s){
        if(t==NULL && s==NULL) return true;
        if(t==NULL) return false;
        if(s==NULL) return false;
        if(t->val==s->val && identical(t->left,s->left) && identical(t->right,s->right)) return true;
        return false;
    }
    bool isSubtree(TreeNode* T, TreeNode* S) {
        if(T==NULL && S==NULL) return true;
        if(T==NULL) return false;
        if(S==NULL) return false;
        if(identical(T,S)) return true;
        bool left=isSubtree(T->left,S);
        bool right=isSubtree(T->right,S);
        return (left || right);
    }
};