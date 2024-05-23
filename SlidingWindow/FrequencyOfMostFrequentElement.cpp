// LEETCODE 1838
// The frequency of an element is the number of times it occurs in an array.
//You are given an integer array nums and an integer k. 
//In one operation, you can choose an index of nums and increment the element at that index by 1.
//Return the maximum possible frequency of an element after performing at most k operations.

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;
        int j=0;
        long long int sum=0;
        int ans=0;
        while(j<n){
            sum+=nums[j];
            if((long long int)(j-i+1)*nums[j]-sum<=k){
                ans=max(ans,j-i+1);
                j++;
            } else {
                while((long long int)(j-i+1)*nums[j]-sum>k){
                    sum-=nums[i];
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};
