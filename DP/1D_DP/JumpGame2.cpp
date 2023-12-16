// LEETCODE 45

/*
if(i==positionn it has reached){
    jumps++
    pos=maxPositionItcanReach
}
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int maxPositionCanReach=0;
        int jumps=0;
        int pos=0;
        for(int i=0;i<n;i++){
            maxPositionCanReach= max(maxPositionCanReach,i+nums[i]);
            if(i==n-1) return jumps;
            if(i==pos){
                jumps++;
                pos=maxPositionCanReach;
            }
        }
        return jumps;
    }
};