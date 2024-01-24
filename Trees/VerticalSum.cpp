/*
Given a Binary Tree, 
find vertical sum of the nodes that are in same vertical line. 
Print all sums through different vertical lines 
starting from left-most vertical line to right-most vertical line.
*/

class Solution{
  public:
    void solve(Node*root,int horizontal_level,map<int,vector<int>>&mp){
        if(root==NULL) return;
        mp[horizontal_level].push_back(root->data);
        solve(root->left,horizontal_level-1,mp);
        solve(root->right,horizontal_level+1,mp);
    }
    vector <int> verticalSum(Node *root) {
        map<int,vector<int>> mp;
        solve(root,0,mp);
        vector<int> ans;
        for(auto it:mp){
            int sum=0;
            for(int a: it.second){
                sum+=a;
            }
            ans.push_back(sum);
        }
        return ans;
    }
}