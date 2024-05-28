// LEETCODE 542

class Solution {
	public:
	vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>> q;
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(matrix[i][j]==0){
                   q.push({i,j});
                   dist[i][j]=0;
               }
           }
       }
        int ans=0;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int i=p.first;
            int j=p.second;
            ans=max(ans,dist[i][j]);
            if(i+1<n && dist[i+1][j]==INT_MAX){
                dist[i+1][j]=dist[i][j]+1;
                q.push({i+1,j});
            }
            if(i-1>=0 && dist[i-1][j]==INT_MAX){
                dist[i-1][j]=dist[i][j]+1;
                q.push({i-1,j});
            }
            if(j+1<m && dist[i][j+1]==INT_MAX){
                dist[i][j+1]=dist[i][j]+1;
                q.push({i,j+1});
            }
            if(j-1>=0 && dist[i][j-1]==INT_MAX){
                dist[i][j-1]=dist[i][j]+1;
                q.push({i,j-1});
            }
        }
		return dist;
	}
};
