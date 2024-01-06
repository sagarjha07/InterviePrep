// LEETCODE 332

class Solution {
public:
    void dfs(string src,map<string,priority_queue<string,vector<string>,greater<string>>> &mp,vector<string> &ans){
        while(!mp[src].empty()){
                string s =mp[src].top();
                mp[src].pop();
                dfs(s,mp,ans); 
        }
        ans.push_back(src);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        if(tickets.size()==0) return ans;
        map<string,priority_queue<string,vector<string>,greater<string>>> mp;
        for(int i=0;i<tickets.size();i++){
            mp[tickets[i][0]].push(tickets[i][1]);
        }
        dfs("JFK",mp,ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};