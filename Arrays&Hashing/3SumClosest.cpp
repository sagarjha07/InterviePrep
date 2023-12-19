// LEETCODE 16

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=INT_MAX;
        int minDiff=INT_MAX;
        for(int i=0;i<n;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<minDiff){
                    minDiff=abs(sum-target);
                    ans=sum;
                }
                if(sum==target){
                    return sum;
                } 
                else if(sum<target) j++;
                else k--;
            } 
        }
        return ans;
    }
};