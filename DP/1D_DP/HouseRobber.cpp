// LEETCODE 198

class Solution {
public:
    int solve(vector<int>&nums, int i, vector<int>&dp){
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        int op1=solve(nums,i+2,dp)+nums[i];
        int op2=solve(nums,i+1,dp);
        return dp[i] = max(op1,op2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp(n+1,-1);
        return solve(nums,0,dp);
    }
};


/// BOTTOM-UP
int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1) return nums[0];
    vector<int> dp(n+1,0);
    dp[0]=0;
    dp[1]=nums[0];
    for(int i=2;i<=n;i++){
        int op1=dp[i-1];
        int op2=INT_MIN;
        if(i>1) {
            op2=dp[i-2]+nums[i-1];
        }
        dp[i]=max(op1,op2);
    }
    return dp[n];
}