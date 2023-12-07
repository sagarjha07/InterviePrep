// DETECT CYCLE UNDIRECTED GRAPH BFS

bool cycleBFS(int V,int src, vector<int> *adj, vector<bool> &visited){
        vector<int> parent(V+1,-1);
        queue<int> q;
        q.push(src);
        visited[src]=true;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            for(int nbr:adj[f]){
                if(visited[nbr]==false){
                    parent[nbr]=f;
                    q.push(nbr);
                    visited[nbr]=true;
                } else if(parent[f]!=nbr) {
                    return true;
                }
            }
        }
        return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V+1,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(cycleBFS(V,i,adj,visited)) return true;
            }
        }
        return false;
    }