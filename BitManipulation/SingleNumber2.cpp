// LEETCODE 137

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int sum=0;
            for(int j=0;j<nums.size();j++){
                int bit = nums[j]>>i & 1;
                sum+=bit;
            }
            sum%=3;
            ans+= sum<<i;
        }
        return ans;
    }
};