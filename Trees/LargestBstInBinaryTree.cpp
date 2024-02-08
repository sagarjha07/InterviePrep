class bst{
  public:
  bool isbst;
  int size;
  int mn;
  int mx;
};
bst solve(Node*root,int&ans){
    bst p;
    if(root==NULL){
        p.size=0;
        p.mn=INT_MAX;
        p.mx=INT_MIN;
        p.isbst=true;
        return p;
    }
    bst l=solve(root->left,ans);
    bst r=solve(root->right,ans);
    if((l.isbst==true) && (r.isbst==true) && (l.mx<root->data && r.mn>root->data)){
        p.size=l.size+r.size+1;
        ans=max(ans,p.size); // calculate max ans at any point of time
        p.mn=min(l.mn,root->data);
        p.mx=max(r.mx,root->data);
        p.isbst=true;
    }
    else{
        p.size=0;
        p.mn=INT_MAX;
        p.mx=INT_MIN;
        p.isbst=false;
    }
    return p;
}
int largestBst(Node *root)
{
    if(root==NULL) return 0;
    int ans=1;
    solve(root,ans);
    return ans;
}