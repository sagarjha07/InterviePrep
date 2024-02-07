class Solution
{
  public:
  
    void inorder(Node*root,Node*&head,Node*&tail){
        if(root==NULL) return;
        inorder(root->left,head,tail);
        if(head==NULL){
            head=root;
            tail=root;
        } else {
            tail->right=root;
            root->left=tail;
            tail=root;
        }
        inorder(root->right,head,tail);
    }
    //Function to convert binary tree into circular doubly linked list.
    Node *bTreeToCList(Node *root)
    {
        if(root==NULL) return NULL;
        Node* head=NULL;
        Node* tail=NULL;
        inorder(root,head,tail);
        tail->right=head;
        head->left=tail;
        return head;
    }
};