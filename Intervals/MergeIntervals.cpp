// lEETCODE 56

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