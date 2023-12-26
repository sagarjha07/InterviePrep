// LEETCODE 131
// Print all palindromes after partitioning

class Solution {
public:
    bool ispalindrome(string s){
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(string s,vector<vector<string>>&ans,vector<string>path){
        if(s.size()==0){
            ans.push_back(path);
            return;
        }
        for(int i=1;i<=s.size();i++){
            string p=s.substr(0,i);
            string rem=s.substr(i);
            if(ispalindrome(p)){
                path.push_back(p);
                solve(rem,ans,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(s,ans,path);
        return ans;
    }
};