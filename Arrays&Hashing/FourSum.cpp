// LEETCODE 18

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>> ans;
        for(int l=0;l<n;l++){
            for(int i=l+1;i<n;i++){
                int j=i+1;
                int k=n-1;
                while(j<k){
                    long long int sum=nums[l]+nums[i];
                    sum+=nums[j]+nums[k];
                    if(sum==target){
                        ans.push_back({nums[l],nums[i],nums[j],nums[k]});
                        int x=nums[j];
                        int y=nums[k];
                        while(j<n && nums[j]==x) j++;
                        while(k>0 && nums[k]==y) k--;
                    } 
                    else if(sum<target) j++;
                    else k--;
                }
                while (i+1<n && nums[i]==nums[i+1]) i++; 
            }
            while(l+1<n && nums[l]==nums[l+1]) l++;
        }
        return ans;
    }
};