// LEETCODE 1547 HARD


// TOP DOWN
class Solution {
public:
    int solve(int i,int j,vector<int>&arr,vector<vector<int>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            int temp= arr[j+1]-arr[i-1]+solve(i,k-1,arr,dp)+solve(k+1,j,arr,dp);
            ans=min(ans,temp);
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,-1));
        return solve(1,cuts.size()-2,cuts,dp);
    }
};


// BOTTOM UP

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(cuts.size()+1,vector<int>(cuts.size()+1,0));
        int c=cuts.size()-2;
        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                if(i>j) continue;
                int temp=INT_MAX;
                for(int k=i;k<=j;k++){
                    temp=min(temp,cuts[j+1]-cuts[i-1]
                    +dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j]=temp;
            }
        }
        return dp[1][c];
    }
};