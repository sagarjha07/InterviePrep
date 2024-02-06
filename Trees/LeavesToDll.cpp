Node* solve(Node* root,Node*&head,Node*&tail){
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        if(head==NULL && tail==NULL){
            head=root;
            tail=root;
        } else {
            tail->right=root;
            root->left=tail;
            tail=tail->right;
        }
        return NULL;
    }
    root->left=solve(root->left,head,tail);
    root->right=solve(root->right,head,tail);
    return root;
}
Node * convertToDLL(Node *root){
    // add code here.
    if(root==NULL) return NULL;
    Node* head=NULL;
    Node* tail=NULL;
    solve(root,head,tail);
    return head;
}