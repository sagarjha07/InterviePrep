//LEETCODE 39 (Print all subsets with given sum)

class Solution {
public:
    void solve(int i,vector<int>&arr,int target,vector<int> &path,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(path);
            return;
        }
        if(i==arr.size() || target<0) return;
        path.push_back(arr[i]);
        solve(i,arr,target-arr[i],path,ans);// include (don't move i,we can again take this element)
        path.pop_back();
        solve(i+1,arr,target,path,ans);//not include
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(0,arr,target,path,ans);
        return ans;
    }
};