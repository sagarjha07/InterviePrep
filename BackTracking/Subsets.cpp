//LEETCODE 78 (Print subsets)

class Solution {
public:
    void solve(int i,vector<int>&nums,vector<int> path,vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(path);
            return;
        }
        path.push_back(nums[i]);
        solve(i+1,nums,path,ans);//include
        path.pop_back();
        solve(i+1,nums,path,ans);//not include
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(0,nums,path,ans);
        return ans;
    }
};