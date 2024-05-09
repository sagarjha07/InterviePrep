// LEETCODE 494

class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n=arr.size();
        int sum=0;
        for(int i:arr) sum+=i;
        sum+=target;
        if(sum&1) return 0;
        sum=sum/2;
        //if sum is negative handle this case also
        if(sum<0) return 0;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=(dp[i-1][j] + dp[i-1][j-arr[i-1]]);
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
		return dp[n][sum];
    }
};


// SPACE OPTIMISED DP

class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int target) {
        int n=arr.size();
        int sum=0;
        for(int i:arr) sum+=i;
        sum+=target;
        if(sum&1) return 0;
        sum=sum/2;
        if(sum<0) return 0;
        vector<int> prev(sum+1,0);
        vector<int> curr(sum+1,0);
        prev[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(arr[i-1]<=j){
                    curr[j]=prev[j]+prev[j-arr[i-1]];
                } else {
                    curr[j]=prev[j];
                }
            }
            prev=curr;
        }
        return prev[sum];
    }
};
