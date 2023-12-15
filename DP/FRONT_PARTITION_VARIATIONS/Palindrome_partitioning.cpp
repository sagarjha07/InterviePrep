// LEETCODE 132

class Solution {
public:
    vector<vector<int>> dp;
    bool isPalindrome(int i,int j,string&s){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, int j, string&s){
        if(i>j) return 0;
        if(isPalindrome(i,j,s)) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<j;k++){
            /* 
                Instead of writing below standard line
                We will recurse for only right part
                Only when left part turns out to be palindrome
				
				Reason : If left substring becomes palindrome then there is no need to partition it further 
				(which in turn reduces the number of recursive calls)
                
                int temp =  solve (s, i, k, dp, palindrome) + solve (s, k+1, j, dp, palindrome) + 1;
                
            */
            if(isPalindrome(i, k, s)){
                int temp = solve(k+1, j, s) + 1;
                ans = min(ans, temp);
            }
        }
        return dp[i][j]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        dp.resize(n+1,vector<int>(n+1, -1));
        return solve(0,n-1,s);
    }
};