// LEETCODE 75

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int m=0;
        int h=n-1;
        while(m<=h){
            if(nums[m]==1){
                m++;
            } else if(nums[m]==0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            } else {
                swap(nums[m],nums[h]);
                h--;
            }
        }
    }
};
