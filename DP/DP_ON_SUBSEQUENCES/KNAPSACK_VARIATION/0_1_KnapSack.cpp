int knapSack(int W, int wt[], int val[], int n) {
    int sum=W;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-wt[i-1]] + val[i-1]);
            }
            else dp[i][j]=dp[i-1][j];
        }
    }
	return dp[n][sum];   
}