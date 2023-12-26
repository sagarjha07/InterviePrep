//LEETCODE 1851

class comp{
    public:
    bool operator()(pair<int,int>& a, pair<int,int>& b)
    {
        return a.second-a.first > b.second-b.first;
    }
};
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<pair<int,int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(intervals.begin(),intervals.end());
        sort(q.begin(),q.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,comp> pq;
        int j=0;
        vector<int> ans(q.size(),-1);
        for(int i=0;i<q.size();i++){
            int x=q[i].first;
            int ind=q[i].second;
            while(j<intervals.size() && intervals[j][0]<=x){
                pq.push({intervals[j][0],intervals[j][1]});
                j++;
            }
            while(!pq.empty() && pq.top().second<x){
                pq.pop();
            }
            if(!pq.empty()){
                ans[ind]=(pq.top().second-pq.top().first+1);
            }
        }
        return ans;
    }
};