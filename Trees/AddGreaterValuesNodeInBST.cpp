
void inorder(Node* root, int&sum){
    if(root==NULL) return;
    inorder(root->right,sum);
    sum+=root->data;
    root->data=sum;
    inorder(root->left,sum);
}
Node* modify(Node *root)
{
    if(root==NULL) return root;
    int sum=0;
    inorder(root,sum);
    return root;
}