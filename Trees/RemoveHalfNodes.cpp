/*
Given A binary Tree. 
Your task is to remove all the half nodes (which has only one child).
*/


Node *RemoveHalfNodes(Node *root)
{
   if(root==NULL) return NULL;
   if(root->left==NULL && root->right==NULL) return root;
   root->left=RemoveHalfNodes(root->left);
   root->right=RemoveHalfNodes(root->right);
   if(root->left!=NULL && root->right==NULL){
       Node*temp=root->left;
       delete(root);
       return temp;
   }
   if(root->left==NULL && root->right!=NULL){
       Node*temp=root->right;
       delete(root);
       return temp;
   }
   return root;
}