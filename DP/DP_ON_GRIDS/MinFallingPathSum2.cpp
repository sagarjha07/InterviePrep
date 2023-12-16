// LEETCODE 1289

// O(N^2) solution
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        vector<int> dp=arr[0];
        for(int i=1;i<n;i++){
            int fm=INT_MAX,sm=INT_MAX,fmIdx;
            for(int j=0;j<n;j++){
                if(dp[j]<fm){
                    fm=dp[j];
                    fmIdx=j;
                }
            }
            for(int j=0;j<n;j++){
                if(j!=fmIdx && dp[j]<sm) sm=dp[j];
            }
            for(int j=0;j<n;j++){
                if(j==fmIdx) dp[j]=arr[i][j]+sm;
                else dp[j]=arr[i][j]+fm;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++) ans=min(ans,dp[i]);
        return ans;
    }
};


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

