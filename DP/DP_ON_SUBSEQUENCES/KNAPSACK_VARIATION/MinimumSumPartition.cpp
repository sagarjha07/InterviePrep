/*
Given an array arr of size n containing non-negative integers, 
the task is to divide it into two sets S1 and S2 
such that the absolute difference between their sums is minimum 
and find the minimum difference
*/

int minDifference(int arr[], int n)  { 
        int sum=0;
        for(int i=0;i<n;i++) sum+=arr[i];
        vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++) dp[i][0]=true;
        for(int j=1;j<=sum;j++) dp[0][j]=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<=sum;j++){
            if(dp[n][j]==true){
                ans=min(ans,abs(sum-2*j));
            }
        }
        return ans;
	} 