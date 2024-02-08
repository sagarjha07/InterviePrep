//LEETCODE 96

class Solution {
public:
    
    int countTrees(int n,vector<int>&dp){
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int count=0;
        for(int i=1;i<=n;i++){
            int leftCount = countTrees(i-1,dp)%mod;
            int rightCount = countTrees(n-i,dp)%mod;
            count= (count + (leftCount*rightCount));
        }
        return dp[n]=count;
    }
    int numTrees(int n) 
    {
        vector<int> dp(n+1,-1);
        return countTrees(n,dp);
    }
};