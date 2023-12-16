// LEETCODE 55
/*
At every index try to find maxPositionCanReach from that index,
if maxPositionCanReach is equal to that index , it means we can't move forward.
If maxPositionCanReach >=n-1 return true
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return true;
        int maxPositionCanReach=0;
        for(int i=0;i<n;i++){
            maxPositionCanReach= max(maxPositionCanReach,i+nums[i]);
            if(i==maxPositionCanReach) return false;
            if(maxPositionCanReach >= n-1) return true;
        }
        return false;
    }
};