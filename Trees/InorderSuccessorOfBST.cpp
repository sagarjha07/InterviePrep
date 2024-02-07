class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* y=x->right;
        Node* ans=NULL;
        if(y!=NULL){
            ans=y;
            while(y->left!=NULL){
                ans=y->left;
                y=y->left;
            }
            return ans;
        }
        while(root!=NULL && root->data!=x->data){
            if(x->data<root->data){
                ans=root;
                root=root->left;
            } else if(x->data>root->data){
                root=root->right;
            }
        }
        return ans;
    }
};