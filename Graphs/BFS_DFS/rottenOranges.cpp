// LEETCODE 994
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({i,j,0});
            }
        }
        int time =0;
        while(!q.empty()){
            vector<int> f=q.front();
            q.pop();
            int i= f[0];
            int j=f[1];
            int t=f[2];
            time=max(time,t);
            if(i+1<n && grid[i+1][j]==1) {
                grid[i+1][j]=2;
                q.push({i+1,j,t+1});
            }
            if(i-1>=0 && grid[i-1][j]==1){
                grid[i-1][j]=2;
                q.push({i-1,j,t+1});
            }
            if(j-1>=0 && grid[i][j-1]==1){
                grid[i][j-1]=2;
                q.push({i,j-1,t+1});
            }
            if(j+1<m && grid[i][j+1]==1) {
                grid[i][j+1]=2;
                q.push({i,j+1,t+1});
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return time;
    }
};