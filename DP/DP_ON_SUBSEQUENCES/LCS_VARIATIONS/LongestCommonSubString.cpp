int LongestCommonSubstr(string X, string Y) {
        
        int m=X.length();
        int n=Y.length();
        int dp[m+1][n+1];
        
        // initialization
        for(int i=0;i<=m;i++)
            dp[i][0]=0;   // Eg LCS of "abc" & "" = 0
        for(int j=0;j<=n;j++)
            dp[0][j]=0;   // Eg LCS of "" & "abc" = 0
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(X[i-1]==Y[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0;                   // ONLY THIS CHANGE
            }
        }
    	 int maxLen=0;              // Now finding the max element
         for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
               maxLen=max(maxLen,dp[i][j]);
        }
        return maxLen;
		}
