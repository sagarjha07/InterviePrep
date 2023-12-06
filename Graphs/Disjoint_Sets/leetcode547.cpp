//547. Number of Provinces
class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        Disjoint d(adj.size());
        for(int i=0;i<adj.size();i++){
            for(int j=i+1;j<adj[0].size();j++){
                if(adj[i][j]==1){
                  d.unionBySize(i,j);
                }
            }
        }
        int ans=0;
        vector<int> parent = d.getParent();
        for (int i=0;i<adj.size();i++) {
          if(parent[i]==i) ans+=1;
        }
        return ans;
    }
};