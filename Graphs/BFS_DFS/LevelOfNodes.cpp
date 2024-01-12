class Solution {
public:
	int levelOfX(int v, vector<int> adj[], int x) {
	    // Code here
	    vector<bool> visited(v,false);
	    queue<int> q;
	    q.push(0);
	    visited[0]=true;
	    int level = 0;
	    while(!q.empty()){
	        int k=q.size();
	        for(int i=0;i<k;i++){
	            int f=q.front();
	            q.pop();
	            if(f==x) return level;
	            for(auto nbr:adj[f]){
	                if(!visited[nbr]){
	                    visited[nbr]=true;
	                    q.push(nbr);
	                }
	            }
	        }
	        level+=1;
	        
	    }
	    return -1;
	}
};