

void solve(Node*root,int horizontal_level,map<int,vector<int>>&mp){
        if(root==NULL) return;
        mp[horizontal_level].push_back(root->data);
        solve(root->left,horizontal_level-1,mp);
        solve(root->right,horizontal_level,mp);
    }
    vector <int> diagonalSum(Node *root) {
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