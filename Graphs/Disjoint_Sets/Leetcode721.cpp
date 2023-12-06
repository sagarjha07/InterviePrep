// LEETCODE 721 Accounts merge 
// Implemnetation wise very good question DSU


class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& arr) {
        unordered_map<string,int> mp;
        int n=arr.size();
        Disjoint d(n);
        for(int i=0;i<n;i++){
            vector<string> v = arr[i];
            for(int j=1;j<v.size();j++){
                if(mp.find(v[j])!=mp.end()){
                    d.unionBySize(i,mp[v[j]]);
                }
                else mp[v[j]]=i;
            } 
        }
        unordered_map<int,vector<string>> mp1;
        for(auto it:mp){
            int parent = d.findParent(it.second);
            mp1[parent].push_back(it.first);
        }
        vector<vector<string>> ans;
        for(auto it:mp1){
            sort(it.second.begin(),it.second.end());
            vector<string> tmp = { arr[it.first][0] };
            tmp.insert( tmp.end(), it.second.begin(), it.second.end() );
            ans.push_back( tmp );
        }
        return ans;
    }
};