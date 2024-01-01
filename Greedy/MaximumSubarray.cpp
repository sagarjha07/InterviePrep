// LEETCODE 53

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int msum=INT_MIN;
        int csum=0;
        for(int i:nums){
            csum=max(csum+i,i);
            msum=max(msum,csum);
        }
        return msum;
    }
};