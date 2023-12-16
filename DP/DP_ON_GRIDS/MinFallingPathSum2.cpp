// LEETCODE 1289
//O(N^3) solution working sinece 1<=n<=200
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int temp=INT_MAX;
                for(int k=0;k<m;k++){
                    if(j==k) continue;
                    temp=min(temp,grid[i+1][k]);
                }
                grid[i][j]=temp+grid[i][j];
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++) ans=min(ans,grid[0][i]);
        return ans;
    }
};