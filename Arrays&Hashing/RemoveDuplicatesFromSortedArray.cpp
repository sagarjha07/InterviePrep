class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        for(int i=0;i<n;i++){
            while(i+1<n && nums[i]==nums[i+1]){
                i++;
            }
            swap(nums[i],nums[j]);
            j++;
        }
        return j;
    }
};
