// Given a Binary Tree. 
// Check whether all of its nodes have the value equal to the sum of their child nodes.


class Solution{
    public:
    //Function to check whether all nodes of a tree have the value 
    //equal to the sum of their child nodes.
    int solve(Node*root,int&ans){
       if(root==NULL) return 0;
       if(root->left==NULL && root->right==NULL) return root->data;
        int lsum = solve(root->left,ans);
        int rsum = solve(root->right,ans);
        if(lsum+rsum!=root->data){
            ans&=false;
        } 
        return root->data;
    }
    int isSumProperty(Node *root)
    {
        int ans=true;
        solve(root,ans);
        return ans;
    }
}