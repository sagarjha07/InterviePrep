// LEETCODE 139

class Solution {
public:
    unordered_map<string,bool> dp;
    bool solve(string s, unordered_set<string> &mp){
        if(s.size()==0) return true;
        if(dp.find(s)!=dp.end()) return dp[s];
        for(int i=0;i<s.size();i++){
            string a=s.substr(0,i+1);
            string b=s.substr(i+1);
            if(mp.find(a)!=mp.end() && solve(b,mp)){
                return dp[s]=true;
            }
        }
        return dp[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> mp;
        for(string &a: wordDict){
            mp.insert(a);
        }
        return solve(s,mp);
    }
};