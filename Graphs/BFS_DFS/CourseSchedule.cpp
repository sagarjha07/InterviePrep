// LEETCODE 207

class Solution {
public:
    bool isCylepresent(int node, vector<int> *adj, vector<bool> &visited, vector<bool> &inStack){
        visited[node]=true;
        inStack[node]=true;
        for(int &nbr: adj[node]){
            if(visited[nbr] && inStack[nbr]) return true;
            else if(!visited[nbr]){
                bool ans=isCylepresent(nbr, adj, visited, inStack);
                if(ans) return true;
            }
        }
        inStack[node]=false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& arr) {
        vector<int> adj[n];
        for(vector<int> &a:arr){
            int u = a[0];
            int v = a[1];
            adj[u].push_back(v);
        }
        vector<bool> visited(n,false);
        vector<bool> inStack(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(isCylepresent(i,adj,visited,inStack)) return false;
            }
        }
        return true;
    }
};