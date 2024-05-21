// LEETCODE 992

// SubarrayWithKDistinct = SubarrayWithAtmostK - SubarrayWithAtmost(K-1) 

class Solution {
public:
    int solve(vector<int>&nums,int k){
        int n=nums.size();
        int ans=0;
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        while(j<n){
            mp[nums[j]]+=1;
            if(mp.size()<=k){
                j++;
            } else {
                while(mp.size()>k){
                    if(mp[nums[i]]==1) mp.erase(nums[i]);
                    else mp[nums[i]]-=1;
                    i++;
                }
                j++;
            }
            ans+=(j-i);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};
