// lEETCODE 56

// APPROACH 1
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;
        sort(v.begin(),v.end());
        ans.push_back(v[0]);
        for(int i=1;i<v.size();i++){
            if(v[i][0]<=ans[ans.size()-1][1]){
                ans[ans.size()-1][1]=max(ans[ans.size()-1][1],v[i][1]);
            }
            else{
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};

// APPROACH 2
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n= intervals.size();
        int i=0;
        vector<vector<int>> ans;
        while(i<n && intervals[i][1]<newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n && intervals[i][0]<=newInterval[1]){
            newInterval[0] = min(intervals[i][0],newInterval[0]);
            newInterval[1] = max(intervals[i][1],newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
