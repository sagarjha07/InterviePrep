// CREATE GRAPH FROM TREE AND THEN APPLY BFS TRAVERSAL

class Solution
{
public:

    vector <int> KDistanceNodes(Node* root, int target , int k)
    {
        vector<int> ans;
       if(root==NULL) return ans;
        unordered_map<int,vector<int>> mp;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* f= q.front();
            q.pop();
            if(f->left){
                mp[f->left->data].push_back(f->data);
                mp[f->data].push_back(f->left->data);
                q.push(f->left);
            }
            if(f->right){
                mp[f->right->data].push_back(f->data);
                mp[f->data].push_back(f->right->data);
                q.push(f->right);
            }
        }
        
        queue<int> q1;
        unordered_map<int,bool> visited;
        q1.push(target);
        visited[target]=true;
        int level=0;
        while(!q1.empty()){
            int k1=q1.size();
            for(int i=0;i<k1;i++){
                int f=q1.front();
                q1.pop();
                if(level==k) ans.push_back(f);
                for(int nbr:mp[f]){
                    if(!visited[nbr]){
                        q1.push(nbr);
                        visited[nbr]=true;
                    }
                }
            }
            level+=1;
        }
        sort(ans.begin(),ans.end());
        return ans; // return the sorted vector of all nodes at k dist
    }
};