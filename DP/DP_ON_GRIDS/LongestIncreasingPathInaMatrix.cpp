//LEETCODE 329

class Solution {
public:
    int dfs(vector<vector<int>>& matrix, int i, int j, int n,int m, vector<vector<int>>& dp,int prev){
          if(i<0 || j<0 || i>=n || j>=m || matrix[i][j]<=prev) return 0;
          if(dp[i][j]!=-1) return dp[i][j];
          int a=dfs(matrix,i+1,j,n,m,dp,matrix[i][j]);
          int b=dfs(matrix,i-1,j,n,m,dp,matrix[i][j]);
          int c=dfs(matrix,i,j+1,n,m,dp,matrix[i][j]);
          int d=dfs(matrix,i,j-1,n,m,dp,matrix[i][j]);
          int ans=max({a,b,c,d})+1;
          return dp[i][j]=ans;
      }
    int longestIncreasingPath(vector<vector<int>>& mat) {
        int n=mat.size();
        if(n==0) return 0;
        int m=mat[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans,dfs(mat,i,j,n,m,dp,INT_MIN));
            }
        }
        return ans;
    }
};