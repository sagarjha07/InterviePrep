class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0;
        int e=n-1;
        int l=-1;
        int r=-1;
        // FIRST OCCURENCE
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                l=mid;
                e=mid-1;
            } else if(nums[mid]<target) s=mid+1;
            else e=mid-1;
        }
        // LAST OCCURENCE
        s=0;
        e=n-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                r=mid;
                s=mid+1;
            } else if(nums[mid]<target) s=mid+1;
            else e=mid-1;
        }
        return {l,r};
    }
};
