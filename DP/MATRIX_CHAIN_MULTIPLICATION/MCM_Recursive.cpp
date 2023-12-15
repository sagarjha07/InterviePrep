class Solution{
public:
    int solve(int i,int j,int *arr,vector<vector<int>>&dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j-1;k++){
            int temp = arr[i-1]*arr[k]*arr[j] + solve(i,k,arr,dp)+solve(k+1,j,arr,dp);
            ans=min(temp,ans);
        }
        return dp[i][j]=ans;
    }
    
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(1,n-1,arr,dp);
    }
};