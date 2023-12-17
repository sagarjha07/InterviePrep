//LEETCODE 44
// TOP-DOWN DP
class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string&s,string&p,int i,int j){
        if(i==s.size() && j==p.size()) return true;
        if(j==p.size()) return false;
        if(i==s.size()){
            while(j!=p.size()){
                if(p[j]!='*') return false;
                j++;
            }
            return true;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?'){
            return dp[i][j]=solve(s,p,i+1,j+1);
        }
        else if(p[j]=='*'){
            return dp[i][j]=solve(s,p,i,j+1) || solve(s,p,i+1,j);
        }
        return dp[i][j]=false;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(s,p,0,0);
    }
};

//BOTTOM UP DP
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        bool dp[n+1][m+1];
        dp[0][0]=true;
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*') dp[0][i]=dp[0][i-1];
            else dp[0][i]=false;
        }
        for(int i=1;i<=n;i++){
            dp[i][0]=false;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j]=dp[i-1][j] || dp[i][j-1];
                else dp[i][j]=false;
            }
        }
        return dp[n][m];
    }
};
