// LEETCODE 91

class Solution {
public:
    vector<int> dp;
    int solve(string&s,int i,int n){
        if(i>=n) return 1;
        if(dp[i]!=-1) return dp[i];
        int d1=s[i]-'0';
        int op1=0;
        if(d1!=0){
            op1+=solve(s,i+1,n);
        }
        int op2=0;
        if(i+1<n){
            int d2=s[i+1]-'0';
            int k=d1*10+d2;
            if(k>=10 && k<=26){
                op2+=solve(s,i+2,n);
            }
        }
        return dp[i]=op1+op2;
    }
    int numDecodings(string s) {
        int n=s.size();
        if(n==0) return 0;
        dp.resize(n+1,-1);
        int ans=solve(s,0,n);
        return ans;
    }
};