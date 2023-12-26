// LEETCODE 40 
//(Tricky while removing duplicates, when we are not picking an element remove all duplicates)

class Solution {
public:
    void solve(int i,vector<int>&arr,int target,vector<int> &path,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(path);
            return;
        }
        if(i==arr.size() || target<0) return;
        path.push_back(arr[i]);
        solve(i+1,arr,target-arr[i],path,ans);// include
        path.pop_back();
        while(i+1<arr.size() && arr[i]==arr[i+1]) i++; // remove duplicates
        solve(i+1,arr,target,path,ans);//not include
    }
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        vector<int> path;
        solve(0,arr,target,path,ans);
        return ans;
    }
};