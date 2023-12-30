// LEETCODE 973

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        vector<pair<int,int>> v;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<p.size();i++){
            int d=p[i][1]*p[i][1]+p[i][0]*p[i][0];
            pq.push({d,i});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            auto it=pq.top();
            ans.push_back(p[it.second]);
            pq.pop();
        }
        return ans;
    }
};