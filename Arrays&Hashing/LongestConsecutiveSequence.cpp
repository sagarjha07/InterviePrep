// LEETCODE 128

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        for(int i:nums) s.insert(i);
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(s.find(nums[i]-1)==s.end()){
                int x=nums[i];
                int count=0;
                while(s.find(x)!=s.end()){
                    count+=1;
                    ans=max(ans,count);
                    x+=1;
                }
            }
        }
        return ans;
    }
};