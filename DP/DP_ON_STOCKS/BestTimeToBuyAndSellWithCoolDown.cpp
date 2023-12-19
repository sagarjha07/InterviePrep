//LEETCODE 309

//TOP-DOWN + MEMOIZATION
class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,vector<int> &prices,int canBuy){
        if(i>=prices.size()) return 0;
        if(dp[i][canBuy]!=-1) return dp[i][canBuy];
        if(canBuy){
            return dp[i][canBuy]=max(-prices[i]+solve(i+1,prices,0),solve(i+1,prices,1));
        } else {
            return dp[i][canBuy]=max(prices[i]+solve(i+2,prices,1),solve(i+1,prices,0));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n+1,vector<int>(3,-1));
        return solve(0,prices,1);
    }
};


//BOTTOM-UP
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(3,0));
        for(int i=n-1;i>=0;i--){
            for(int canBuy=0;canBuy<=1;canBuy++){
                if(canBuy) dp[i][canBuy]=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                else dp[i][canBuy]=max(prices[i]+dp[i+2][1],dp[i+1][0]);
            }
        }
        return dp[0][1];
    }
};