class Solution{
public:
  
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++) dp[i][i]=0;
        for(int i=n-1;i>=1;i--){
            for(int j=i+1;j<=n-1;j++){
                int temp=INT_MAX;
                for(int k=i;k<=j-1;k++){
                    temp=min(temp,dp[i][k]+dp[k+1][j] + arr[i-1]*arr[k]*arr[j]);
                }
                dp[i][j]=temp;
            }
        }
        return dp[1][n-1];
    }
};