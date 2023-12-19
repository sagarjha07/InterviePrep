// LEETCODE 123

//TOP-DOWN + MEMOIZATION
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,vector<int> &prices,int transactionNumber,int k){
        if(i==prices.size() || transactionNumber==2*k) return 0;
        if(dp[i][transactionNumber]!=-1) return dp[i][transactionNumber];
        if(transactionNumber%2==0){
            return dp[i][transactionNumber]=max(-prices[i]+solve(i+1,prices,transactionNumber+1,k),solve(i+1,prices,transactionNumber,k));
        } else {
            return dp[i][transactionNumber]=max(prices[i]+solve(i+1,prices,transactionNumber+1,k),solve(i+1,prices,transactionNumber,k));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int k=2;
        dp.resize(n+1,vector<int>(2*k+1,-1));
        return solve(0,prices,0,2);
    }
};


//BOTTOM-UP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int k=2;
        vector<vector<int>> dp(n+1,vector<int>(2*k+1,0));
        for(int i=n-1;i>=0;i--){
            for(int transactionNumber=0;transactionNumber<2*k;transactionNumber++){
                if(transactionNumber%2==0) dp[i][transactionNumber]=max(-prices[i]+dp[i+1][transactionNumber+1],dp[i+1][transactionNumber]);
                else dp[i][transactionNumber]=max(prices[i]+dp[i+1][transactionNumber+1],dp[i+1][transactionNumber]);
            }
        }
        return dp[0][0];
    }
};