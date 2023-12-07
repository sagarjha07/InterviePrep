class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        vector<int> color(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1) {
                q.push(i);
                color[i]=0;
                while(!q.empty()){
                    int f=q.front();
                    q.pop();
                    for(int nbr:graph[f]) {
                        if(color[nbr]==-1) {
                            color[nbr] = 1-color[f];
                            q.push(nbr);
                        }
                        else if(color[nbr]==color[f]) return false;
                    }
                }
            }
        }
        return true;
    }
};