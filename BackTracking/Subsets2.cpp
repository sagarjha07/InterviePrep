//LEETCODE 90

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
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++; // remove duplicates
        solve(i+1,nums,path,ans);//not include
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> path;
        solve(0,nums,path,ans);
        return ans;
    }
};