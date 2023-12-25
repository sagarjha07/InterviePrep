// LEETCODE 22
// GENERATE BALANCED PARENTHESES

class Solution {
public:
    void solve(int n,int open,int close,string s,vector<string>&ans){
        if(open==n && close==n){
            ans.push_back(s);
            return;
        } 
        if(open<n){
            solve(n,open+1,close,s+'(',ans);
        }
        if(close<open) {
            solve(n,open,close+1,s+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int open=0;
        int close=0;
        solve(n,open,close,"",ans);
        return ans;
    }
};