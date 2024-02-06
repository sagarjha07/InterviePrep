
class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int dist(Node* root, int k, int level)
    {
        if (root == NULL)
            return -1;
        if (root->data == k)
            return level;
     
        int left = dist(root->left, k, level + 1);
        if (left == -1)
            return dist(root->right, k, level + 1);
        return left;
    }
    Node* lca(Node* root,int a,int b){
        if(root==NULL) return NULL;
        if(root->data==a) return root;
        if(root->data==b) return root;
        Node* l = lca(root->left,a,b);
        Node* r = lca(root->right,a,b);
        if(l!=NULL && r!=NULL) return root;
        if(l!=NULL) return l;
        if(r!=NULL) return r;
    }
    int findDist(Node* root, int a, int b) {
        if(root==NULL) return -1;
        Node* lc = lca(root,a,b);
        int w1 = dist(lc,a,0);
        int w2 = dist(lc,b,0);
        return w1+w2;
    }
};