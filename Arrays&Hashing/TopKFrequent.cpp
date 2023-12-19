// LEETCODE 347

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]+=1;
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        for(auto it:mp){
            int freq=it.second;
            int x=it.first;
            pq.push({freq,x});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            vector<int> v=pq.top();
            pq.pop();
            ans.push_back(v[1]);
        }
        return ans;
    }
};