Node *deleteNode(Node *root, int x) {
    if(root==NULL) return root;
    if(x<root->data){
        root->left = deleteNode(root->left,x);
        return root;
    }
    if(x>root->data){
        root->right = deleteNode(root->right,x);
        return root;
    }
    if(x==root->data){
        if(root->left==NULL && root->right==NULL){
            delete(root);
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL){
            Node*temp=root->left;
            delete(root);
            return temp;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node*temp=root->right;
            delete(root);
            return temp;
        }
        else{
            Node*temp=root->right;
            while(temp->left!=NULL) temp=temp->left;
            swap(root->data,temp->data);
            root->right=deleteNode(root->right,temp->data);
        }
        return root;
    }
}