// Surrounded regoions
// Replace all 'O' with 'X'
// Call BFS for all 'O's in boundary rows and cloumns and change all 'O's to connected with another char

class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<vector<int>> q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                if(i==n-1 || j==m-1 || i==0 || j==0) {
                    if(grid[i][j]=='O'){
                      q.push({i,j});
                      grid[i][j]='#';
                    }
                }
            }
        }
        while(!q.empty()){
            vector<int> f=q.front();
            q.pop();
            int i=f[0];
            int j=f[1];
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            for(int k=0;k<4;k++){
                int r=i+dx[k];
                int c=j+dy[k];
                if(r<n && c<m && r>=0 && c>=0 && grid[r][c]=='O') {
                  q.push({r,c});
                  grid[r][c]='#';
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O') grid[i][j]='X';
                else if(grid[i][j]=='#') grid[i][j]='O';
            }
        }
    }
};