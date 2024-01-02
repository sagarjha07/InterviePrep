//LEETCODE 130

class Solution {
public:
    void dfs(int i,int j,int n,int m, vector<vector<char>>& grid){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!='O') return;
        grid[i][j]='#';
        dfs(i+1,j,n,m,grid);
        dfs(i-1,j,n,m,grid);
        dfs(i,j+1,n,m,grid);
        dfs(i,j-1,n,m,grid);
    }
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]=='O'){
                        dfs(i,j,n,m,grid);
                    }
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