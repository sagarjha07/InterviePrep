//LEETCODE 1

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int i=0;
        int j=arr.size()-1;
        vector<vector<int>> nums;
        for(int i=0;i<arr.size();i++){
            nums.push_back({arr[i],i});
        }
        sort(nums.begin(),nums.end());
        vector<int> ans;
        while(i<j){
            int sum=nums[i][0]+nums[j][0];
            if(sum==target){
                ans.push_back(nums[i][1]);
                ans.push_back(nums[j][1]);
                return ans;
            }
            else if(sum>target) j--;
            else i++;
        }
        return ans;
    }
};