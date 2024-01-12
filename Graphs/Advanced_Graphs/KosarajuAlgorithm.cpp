/*
Implementation:
---> Perform DFS traversal of the graph. Push node to stack before returning(stores node in descending order of Popping  time).
---> Find the transpose graph by reversing the edges.
---> Pop nodes one by one from the stack and again to DFS on the modified graph and increase count of scc for every dfs  traversal.
*/


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs2(int node,vector<bool>&visited,vector<int>*adj){
	    visited[node]=true;
	    for(int nbr:adj[node]){
	        if(!visited[nbr]){
	            dfs2(nbr,visited,adj);
	        }
	    }
	}
	void dfs(int node,vector<bool>&visited,vector<int>*adj,stack<int>&s){
	    visited[node]=true;
	    for(int nbr:adj[node]){
	        if(!visited[nbr]){
	            dfs(nbr,visited,adj,s);
	        }
	    }
	    s.push(node);
	}
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool> visited(V,false);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs(i,visited,adj,s);
            }
        }
        vector<int> rev[V];
        for(int i=0;i<V;i++){
            vector<int> v=adj[i];
            for(int j=0;j<v.size();j++){
                rev[v[j]].push_back(i);
            }
        }
        for(int i=0;i<V;i++) visited[i]=false;
        int ans=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            if(!visited[node]){
                dfs2(node,visited,rev);
                ans+=1;
            }
        }
        return ans;
    }
};