// DETECT CYCLE IN A DIRECTED GRAPH (DFS)

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool dfs(int node,vector<int>*adj,vector<bool>&visited,vector<bool>&instack){
	    visited[node]=true;
	    instack[node]=true;
	    for(int nbr:adj[node]){
	        if(instack[nbr]==true) return true;
	        if(!visited[nbr]){
	            bool ans=dfs(nbr,adj,visited,instack);
	            if(ans) return true;
	        }
	    }
	    instack[node]=false;
	    return false;
	}
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V,false);
	    vector<bool> instack(V,false);
	    for(int i=0;i<V;i++){
	        if(!visited[i]){
	            if(dfs(i,adj,visited,instack)) return true;
	        }
	    }
	    return false;
	}
};