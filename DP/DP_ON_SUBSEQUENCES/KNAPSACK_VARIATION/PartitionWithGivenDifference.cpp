int countPartitions(int n, int d, vector<int>& arr) {
    int sum=0;
    for(int i:arr) sum+=i;
        sum+=d;
        if(sum&1) return 0;
        sum=sum/2;
		int mod=1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=(dp[i-1][j]%mod + dp[i-1][j-arr[i-1]]%mod)%mod;
                }
                else dp[i][j]=dp[i-1][j]%mod;
            }
        }
		return dp[n][sum]%mod;
}