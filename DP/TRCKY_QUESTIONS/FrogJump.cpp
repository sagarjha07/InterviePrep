//LEETCODE 403

class Solution {
public:
    bool solve(int i,int k,vector<int>&arr,vector<vector<int>>&dp){
        if(i==arr.size()-1) return true;
        if(dp[i][k]!=-1) return dp[i][k];
        for(int j=i+1;j<arr.size();j++){
            int gap=arr[j]-arr[i];
            if(gap>=k-1 && gap<=k+1){
                bool ans = solve(j,gap,arr,dp);
                if(ans) return dp[i][k]=ans;
            }
        }
        return dp[i][k]=false;
    }
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        if(stones[1]-stones[0]>1) return false;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,1,stones,dp);
    }
};