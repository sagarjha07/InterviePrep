// LEETCODE 115

// RECURSIVE
class Solution {
public:
    int dp[1005][1005];
    int solve(string s,string t,int i,int j){
        if(i==s.size() && j==t.size()) return 1;
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=solve(s,t,i+1,j+1)+solve(s,t,i+1,j);
        }
        return dp[i][j]=solve(s,t,i+1,j);
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(s,t,0,0);
    }
};

//BOTTOM-UP 
int numDistinct(string a, string b) {
    int m = a.size(),n=b.size();
    vector<vector<unsigned long long>> dp(m+1,vector<unsigned long long>(n+1,0));//unsigned long long int is used to avoid overflow for bigger values
    for(int i=0;i<=m;i++)//if b is empty then there is only 1 subsequence by not including any character from a
            dp[i][0] = 1;
    for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i-1]==b[j-1])//when there is match we can add values of 2 case
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-1];//1. we don't include this character of a 2. we include it
                else
                    dp[i][j] = dp[i-1][j];//just use the best value before this character of a
            }
        }
        return dp[m][n];//return best value
}

//BOTTOM-UP OPTIMISED DP
class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<unsigned long long int > prev(m+1,0);
        vector<unsigned long long int> curr(m+1,0);
        prev[0]=1;
        for(int i=1;i<=n;i++){
            curr[0]=1;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    curr[j]=prev[j-1] + prev[j];
                } else curr[j]=prev[j];
            }
            prev=curr;
        }
        return prev[m];
    }
};