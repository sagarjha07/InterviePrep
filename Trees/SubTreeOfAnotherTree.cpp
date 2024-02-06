// LEETCODE 572

class Solution {
public:
    bool identical(TreeNode*t,TreeNode*s){
        if(t==NULL && s==NULL) return true;
        if(t==NULL) return false;
        if(s==NULL) return false;
        if(t->val==s->val && identical(t->left,s->left) && identical(t->right,s->right)) return true;
        return false;
    }
    bool isSubtree(TreeNode* T, TreeNode* S) {
        if(T==NULL && S==NULL) return true;
        if(T==NULL) return false;
        if(S==NULL) return false;
        if(identical(T,S)) return true;
        bool left=isSubtree(T->left,S);
        bool right=isSubtree(T->right,S);
        return (left || right);
    }
};




// GFG BFS APPROACH

class Solution
{
    public:
    //Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root) 
    {
        vector<int> ans;
        if(root==NULL) return ans;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* f = q.front();
            q.pop();
            if(f==NULL) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(f->data);
                q.push(f->left);
                q.push(f->right);
            }
        }
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &v)
    {
       if(v.size()==0) return NULL;
       int ind =0;
       Node* root= new Node(v[0]);
       queue<Node*> q;
       q.push(root);
       ind++;
       while(!q.empty()){
           Node* f= q.front();
           q.pop();
           if(v[ind]==-1) {
               ind++;
               f->left=NULL;
           }
           else if(v[ind]!=-1){
               Node* l = new Node(v[ind]);
               f->left =l;
               q.push(l);
               ind++;
           }
           if(v[ind]==-1) {
               ind++;
               f->right=NULL;
           }
           else if(v[ind]!=-1){
               Node* r = new Node(v[ind]);
               f->right = r;
               q.push(r);
               ind++;
           }
       }
       return root;
    }

}