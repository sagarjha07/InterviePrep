// LEETCODE 698

class Solution {
public:
    bool solve(vector<int>&nums,int i,int bucketNum, int cBucketSum,int targetSum,int k,vector<bool>&alreadyVisited){
        if(bucketNum>k) return true;
        if(cBucketSum==targetSum){
            return solve(nums,0,bucketNum+1,0,targetSum,k,alreadyVisited);
        }
        if(i>=nums.size()) return false;
        if(alreadyVisited[i]){
            return solve(nums,i+1,bucketNum,cBucketSum,targetSum,k,alreadyVisited);
        } else {
            //include
            cBucketSum+=nums[i];
            alreadyVisited[i]=true;
            bool op1 = solve(nums,i+1,bucketNum,cBucketSum,targetSum,k,alreadyVisited);
            cBucketSum-=nums[i];
            alreadyVisited[i]=false;

            //not include
            bool op2 = solve(nums,i+1,bucketNum,cBucketSum,targetSum,k,alreadyVisited);
            return op1 || op2;
        }
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1) return true;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum%k!=0) return false;
        vector<bool> alreadyVisited(n+1);
        int targetSum=sum/k;
        return solve(nums,0,1,0,targetSum,k,alreadyVisited);
    }
};