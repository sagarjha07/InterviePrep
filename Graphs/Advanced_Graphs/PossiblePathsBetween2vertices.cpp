class Solution 
{
    public:
    //Function to count paths between two vertices in a directed graph.
    void dfs(vector<int>*adj,int s,int d,vector<bool>&visited,int&ans){
        if(s==d){
            ans+=1;
            return;
        }
        visited[s]=true;
        for(int nbr:adj[s]){
            if(!visited[nbr]){
                dfs(adj,nbr,d,visited,ans);
            }
        }
        visited[s]=false;
    }
	int countPaths(int V, vector<int> adj[], int s, int d)
	{
	    vector<bool> visited(V,false);
	    int ans=0;
	    dfs(adj,s,d,visited,ans);
	    return ans;
	}
};