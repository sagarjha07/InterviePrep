// LEETCODE 763

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[s[i]]=i;
        int j=0;
        int mx=0;
        for(int i=0;i<n;i++){
            mx=max(mx,mp[s[i]]);
            if(mx==i){
                ans.push_back(i-j+1);
                j=i+1;
            }
        }
        return ans;
    }
};