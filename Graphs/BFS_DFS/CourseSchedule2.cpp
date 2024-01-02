// LEETOCDE 210

class Solution {
public:
    bool dfs_cycle_check(int node,unordered_map<int,vector<int>> &mp,unordered_map<int,bool>&visited,unordered_map<int,bool>&instack,vector<int>&ans){
        visited[node]=true;
        instack[node]=true;//activate node
        for(int nbr:mp[node]){
            if(instack[nbr]==true) return true;
            if(!visited[nbr]){
                if(dfs_cycle_check(nbr,mp,visited,instack,ans)) return true;
            }
        }
        instack[node]=false;//deactivate node
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> ans;
        unordered_map<int,bool> visited,instack;
        for(int i=0;i<numCourses;i++){
            if(!visited[i]){
                if(dfs_cycle_check(i,mp,visited,instack,ans)) return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};