// LEETCODE 152

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = 1;
        int mini = 1;
        int ans = INT_MIN;
        for(int i = 0;i < nums.size();i++){
            if(nums[i]<0) swap(maxi,mini);
            maxi = max({nums[i],maxi*nums[i]});
            mini = min({nums[i],mini*nums[i]});
            ans = max(ans,maxi);
        }
        return ans;
    }
};
