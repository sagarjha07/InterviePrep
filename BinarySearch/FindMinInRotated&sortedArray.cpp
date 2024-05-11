// LEETCODE 153

class Solution {
public:
    int solve(vector<int>&arr,int s,int e){
        while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]<arr[mid+1] && arr[mid]<arr[mid-1]){
                return arr[mid];
            } else if(arr[mid]>arr[0]){
                s=mid+1;
            } else e=mid-1;
        }
        return -1;
    }
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int ans=solve(nums,1,n-2);
        if(ans!=-1) return ans;
        return min(nums[0],nums[n-1]);
    }
};
