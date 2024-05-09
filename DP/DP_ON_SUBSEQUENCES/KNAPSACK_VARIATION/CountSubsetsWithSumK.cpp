int findWays(vector<int>& arr, int sum)
{
		int n=arr.size();
		int mod=1e9+7;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        dp[0][0]=1;
        //for handling elements with zero value 
        // just fill dp[0][0]=1 and don't fill first element of each row
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


// SPACE OPTIMISED DP
int perfectSum(int arr[], int n, int w){
	vector<int> prev(w+1,0);
	vector<int> curr(w+1,0);
        prev[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=w;j++){
                if(arr[i-1]<=j){
                    curr[j]=prev[j] + prev[j-arr[i-1]];
                } else {
                    curr[j] = prev[j];
                }
            }
            prev=curr;
        }
        return prev[w];
	}
