// LEETCODE 189

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int candidate=nums[0];
        int count=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==candidate){
                count+=1;
            } else {
                count-=1;
                if(count==0) {
                    candidate=nums[i];
                    count=1;
                }
            }
        }
        count=0;
        for(int i:nums){
            if(candidate==i) count+=1;
        }
        return count>n/2?candidate:-1;
    }
};
