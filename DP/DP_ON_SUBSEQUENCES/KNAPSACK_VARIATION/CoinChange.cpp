// LEETCODE 322 Coin Change

//RECURSIVE
class Solution {
public:
    int dp[100001];
    int a;
    int solve(vector<int>&coins,int n){
        if(n==0) return 0;
        if(n<0) return a+1;
        if(dp[n]!=-1) return dp[n];
        int ans=a+1;
        for(int i=0;i<coins.size();i++){
            if(n>=coins[i]) ans=min(ans,solve(coins,n-coins[i])+1);
        }
        return dp[n]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        memset(dp,-1,sizeof(dp));
        a=amount;
        int ans= solve(coins,amount);
        return ans>amount?-1:ans;
    }
};

// BOTTOM-UP

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i){
                    dp[i]=min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        if((int)dp[amount]>amount) return -1;
        return (int)dp[amount];
    }
};

