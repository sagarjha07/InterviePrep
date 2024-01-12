class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int node, vector<int>*adj,vector<bool>&visited){
        visited[node]=true;
        for(int &nbr:adj[node]){
            if(!visited[nbr]){
                dfs(nbr,adj,visited);
            }
        }
    }
	int findMotherVertex(int v, vector<int>adj[])
	{
	    // Code here
	    vector<bool> visited(v+1,false);
	    int potentialMother=0;
	    for(int i=0;i<v;i++){
	        if(!visited[i]){
	            dfs(i,adj,visited);
	            potentialMother=i;
	        }
	    }
	    visited.assign(v+1,false);
	    dfs(potentialMother,adj,visited);
	    for(int i=0;i<v;i++){
	        if(!visited[i]) return -1;
	    }
	    return potentialMother;
	}

};