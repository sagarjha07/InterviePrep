// LEETCODE 229

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=INT_MAX;
        int c2=INT_MAX;
        int count1=0;
        int count2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==c1){
                count1+=1;
            } else if (nums[i]==c2){
                count2+=1;
            } else if (count1==0){
                c1=nums[i];
                count1=1;
            } else if(count2==0 && c1!=nums[i]){
                c2=nums[i];
                count2=1;
            } else {
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int i:nums){
            if(c1==i) count1++;
            else if(c2==i) count2++;
        }
        vector<int> ans;
        if(count1>nums.size()/3) ans.push_back(c1);
        if(count2>nums.size()/3) ans.push_back(c2);
        return ans;
    }
};
