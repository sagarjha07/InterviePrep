class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       //MST --> connect all the n nodes with n-1 edges only such that weight of that tree is minimum
       //sort all the edges according to weight
       //for every edge check whether they have same parent or not.
       //if not same parent. Join the nodes using union and add weight to MST
       // if same parent don't add the weight otherwise number of edge will increase and it will not become MST
       
       vector<vector<int>> edges;
       for(int i=0;i<V;i++){
           vector<vector<int>> v = adj[i];
           for(int j=0;j<v.size();j++){
               vector<int> a=v[j];
               edges.push_back({a[1],i,a[0]});
           }
       }
       int ans=0;
       sort(edges.begin(),edges.end());
       Disjoint d(V);
       for(vector<int> e: edges){
           int a = d.findParent(e[1]);
           int b = d.findParent(e[2]);
           if(a!=b) {
               ans+=e[0];
               d.unionBySize(e[1],e[2]);
           }
       }
       return ans;
    }
};