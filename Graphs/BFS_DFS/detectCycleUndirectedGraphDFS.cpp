class Solution 
{
    public:
    bool dfs(int node,vector<int>*adj,int par,vector<bool>&visited){
	    visited[node]=true;
	   // instack[node]=true;
	    for(int nbr:adj[node]){
	        if(visited[nbr]==true && par!=nbr) return true;
	        if(!visited[nbr]){
	            bool ans=dfs(nbr,adj,node,visited);
	            if(ans) return true;
	        }
	    }
	   // instack[node]=false;
	    return false;
	}
	bool isCycle(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V,false);
	   //
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            if(dfs(i,adj,-1,visited)) return true;
	        }
	    }
	    return false;
	}
};