// LEETCODE 213 House Robber 2

class Solution {
public:
    int solve(vector<int>& nums) {
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
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> arr1,arr2;
        for(int i=0;i<n-1;i++) arr1.push_back(nums[i]);
        for(int i=1;i<n;i++) arr2.push_back(nums[i]);
        return max(solve(arr1),solve(arr2));
    }
};