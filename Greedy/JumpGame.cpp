// LEETCODE 55

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int maxPosCanReach=0;
        for(int i=0;i<n;i++){
            maxPosCanReach=max(maxPosCanReach,i+nums[i]);
            if(i==maxPosCanReach) return false;
            if(maxPosCanReach >= n-1) return true;
        }
        return true;
    }
};