class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0){
            if(nums[i]<nums[i+1]){
                break;
            }
            i--;
        }
        if(i<0) {
            reverse(nums.begin(),nums.end());
            return;
        }
        int val=nums[i];
        int j=n-1;
        while(j>=0){
            if(nums[j]>val){
                swap(nums[j],nums[i]);
                break;
            }
            j--;
        }
        sort(nums.begin()+i+1,nums.end());
        return;
    }
};
