//LEETCODE 1043
// Partition Array for Maximum Sum
//f(i) represent give me the maximum sum if you have array from i 

class Solution {
public:
    int solve(int i,int k,int n,vector<int>&arr,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MIN;
        int len=0;
        int maxi=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int temp=len*maxi + solve(j+1,k,n,arr,dp);
            ans=max(ans,temp);
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(n,-1);
        return solve(0,k,n,arr,dp);
    }
};
