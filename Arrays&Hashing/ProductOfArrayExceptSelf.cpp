// LEETCODE 238

//O(N) Extra Space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,1);
        vector<int> right(n+1,1);
        left[0]=1;
        right[n-1]=1;
        for(int i=1;i<n;i++) left[i]=left[i-1]*nums[i-1];
        for(int i=n-2;i>=0;i--) right[i]=right[i+1]*nums[i+1];
        vector<int> ans;
        for(int i=0;i<n;i++) ans.push_back(left[i]*right[i]);
        return ans;
    }
};

//O(1) Extra Space
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int left=1;
        int right=1;
        vector<int> ans;
        for(int i=0;i<n;i++){
            ans.push_back(left);
            left*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            ans[i]*=right;
            right*=nums[i];
        }
        return ans;
    }
};