// LEETCODE 1248
// Given an array of integers nums and an integer k.
//A continuous subarray is called nice if there are k odd numbers on it.
// Return the number of nice sub-arrays.

Return the number of nice sub-arrays.

class Solution {
public:
    int solve(vector<int>&nums,int k){
        if(k<0) return 0;
        int n=nums.size();
        int i=0;
        int j=0;
        int count=0;
        int ans=0;
        while(j<n){
            if(nums[j]%2==1) count+=1;
            if(count<=k){
                j++;
            } else if(count>k){
                while(count>k){
                    if(nums[i]%2==1) count-=1;
                    i++;
                }
                j++;
            }
            //add in last the num of subarrays
            ans+=(j-i);
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k)-solve(nums,k-1);
    }
};
