// CREATE GRAPH FROM TREE AND APPLY BFS
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
        if(root==NULL) return 0;
        unordered_map<int,vector<int>> mp; // GRAPH
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* f= q.front();
            q.pop();
            if(f->left){
                mp[f->data].push_back(f->left->data);
                mp[f->left->data].push_back(f->data);
                q.push(f->left);
            }
            if(f->right){
                mp[f->data].push_back(f->right->data);
                mp[f->right->data].push_back(f->data);
                q.push(f->right);
            }
        }
        
        // GRAPH CREATED, NOW APPLY GRAPH BFS
        int time_taken=0;
        queue<int> q1;
        unordered_map<int,bool> visited;
        q1.push(target);
        visited[target]=true;
        while(!q1.empty()){
            int k=q1.size();
            time_taken+=1;
            for(int i=0;i<k;i++){
                int f=q1.front();
                q1.pop();
                for(int nbr:mp[f]){
                    if(!visited[nbr]){
                        visited[nbr]=true;
                        q1.push(nbr);
                    }
                }
            }
        }
        return time_taken-1;
    }
}