// LEETCODE 632
//  Smallest Range Covering Elements from K Lists

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& arr) {
        typedef pair<int,pair<int,int>> pii;
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        int start;
        int end;
        int range=INT_MAX;
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i][0],{i,0}});
            mx=max(mx,arr[i][0]);
        }
        while(pq.size()>=arr.size()){
            pii f=pq.top();
            pq.pop();
            int i=f.second.first;
            int j=f.second.second;
            mn=f.first;
            if(range>(mx-mn)){
                range=mx-mn;
                start=mn;
                end=mx;
            }
            if(j+1<arr[i].size()){
                pq.push({arr[i][j+1],{i,j+1}});
                mx=max(mx,arr[i][j+1]);
            }
        }
        return {start,end};
    }
};
