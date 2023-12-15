//LEETCODE 368

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // 1 4 3 12 9 6 2
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size(),1);
        unordered_map<int,int> parent;
        parent[0]=0;
        int maxi=1;
        int last_index=0;
        for(int i=1;i<nums.size();i++){
            parent[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    parent[i] = j;
                }
            }
            if(dp[i]>maxi){
                maxi=max(maxi,dp[i]);
                last_index=i;
            }
        }
        vector<int> ans;
        while(parent[last_index]!=last_index){
            ans.push_back(nums[last_index]);
            last_index=parent[last_index];
        }
        ans.push_back(nums[last_index]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};