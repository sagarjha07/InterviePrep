/*
Given a Binary Tree find the length of the longest path 
which comprises of connected nodes with consecutive values in increasing order. 
*/

class Solution{
  public:
    // your task is tp complete this function
    // function should return the length of the longestConsecutive
    // sequence
    void solve(Node* root, int curLen, int expected,int &ans){
        if(root==NULL) return;
        if(root->data==expected){
            curLen+=1;
        } else curLen=1;
        ans=max(ans,curLen);
        solve(root->left,curLen,root->data+1,ans);
        solve(root->right,curLen,root->data+1,ans);
    }
    int longestConsecutive(Node* root)
    {
        if(root==NULL) return -1;
        int ans = -1;
        int expected=-1;
        solve(root,0,expected,ans);
        if(ans==1) return -1;
        return ans;
    }
};