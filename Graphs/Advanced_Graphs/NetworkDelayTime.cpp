// LEETCODE 743
// Use Djikstra Algorithm
// find min distance from kth node to every node
// ans will be maximum dist of all the distance array.
// if ans is INT_MAX, then there is a node where which can't reach
// then return -1 and if ans is not INT_MAX then return ans;

class compare{
    public:
        bool operator()(vector<int>&a,vector<int>&b){
            return a[1]>b[1];
        }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto & a: times){
            int u=a[0];
            int v=a[1];
            int w=a[2];
            adj[u].push_back({v,w});
        }
        vector<int> disTo(n + 1, INT_MAX);
        disTo[k] = 0;
        queue<pair<int, int>> q;
        q.push({0, k});
        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto curr = q.front();
                q.pop();
                int node = curr.second;
                int cost = curr.first;

                for (auto it : adj[node]) {
                    if (cost + it.second < disTo[it.first]) {
                        disTo[it.first] = cost + it.second;
                        q.push({disTo[it.first], it.first});
                    }
                }
            }
        }
        int ans=INT_MIN;
        for(int i=1;i<=n;i++){
            ans=max(ans,disTo[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};