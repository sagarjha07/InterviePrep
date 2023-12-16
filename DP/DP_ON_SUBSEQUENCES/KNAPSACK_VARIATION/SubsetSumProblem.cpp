//RECURSIVE + MEMOIZATION
class Solution{   
public:
    vector<vector<int>> dp;
    bool solve(int i,int n,vector<int>&arr,int sum){
        if(sum==0) return true;
        if(i==n) return false;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool op1=false;
        if(arr[i]<=sum) op1=solve(i+1,n,arr,sum-arr[i]);
        bool op2=solve(i+1,n,arr,sum);
        return dp[i][sum]=op1||op2;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        dp.resize(n+1,vector<int>(sum+1,-1));
        return solve(0,n,arr,sum);
    }
};

//BOTTOM UP (TABULATION) (KNAPSACK VARIATION)
class Solution{   
public:
    vector<vector<bool>> dp;
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        dp.resize(n+1,vector<bool>(sum+1,false));
        for(int i=0;i<=n;i++) dp[i][0]=true;
        for(int j=1;j<=sum;j++) dp[0][j]=false;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j]=dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};

