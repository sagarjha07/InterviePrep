// LEETCODE 110

class HBPair {
public:
    bool isBalanced;
    int height;
};
class Solution {
public:
    HBPair solve(TreeNode* root){
        HBPair p;
        if(root==NULL){
            p.isBalanced=true;
            p.height=0;
            return p;
        }
        HBPair leftPair = solve(root->left);
        HBPair rightPair = solve(root->right);
        p.height=max(leftPair.height,rightPair.height)+1;
        if(leftPair.isBalanced && rightPair.isBalanced && abs(leftPair.height-rightPair.height)<=1){
            p.isBalanced=true;
        } else {
            p.isBalanced=false;
        }
        return p;
    }
    bool isBalanced(TreeNode* root) {
        HBPair ans = solve(root);
        return ans.isBalanced;
    }
};