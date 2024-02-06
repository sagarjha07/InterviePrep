class Solution
{
    public: 
    
    //Function to convert binary tree to doubly linked list and return it.
    void inorder(Node*root,Node*&head,Node*&tail){
        if(root==NULL) return;
        inorder(root->left,head,tail);
        if(head==NULL && tail==NULL){
             head=root;
            tail=root;
        } else {
            tail->right=root;
            root->left=tail;
            tail=root;
        }
        inorder(root->right,head,tail);
    }
    Node * bToDLL(Node *root)
    {
        if(root==NULL) return NULL;
        Node* head=NULL;
        Node* tail=NULL;
        inorder(root,head,tail);
        return head;
    }
};