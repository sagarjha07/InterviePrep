// LEETCODE 695

class Solution {
public:
    void dfs(int i,int j,int n,int m, vector<vector<int>>& grid,int &size){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==2 || grid[i][j]==0) return;
        grid[i][j]=2;
        size+=1;
        dfs(i+1,j,n,m,grid,size);
        dfs(i-1,j,n,m,grid,size);
        dfs(i,j+1,n,m,grid,size);
        dfs(i,j-1,n,m,grid,size);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int temp=0;
                    dfs(i,j,n,m,grid,temp);
                    ans=max(ans,temp);
                }
            }
        }
        return ans;
    }
};