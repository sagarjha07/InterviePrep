class Solution {
public:
    int lowerbound(vector<int>&temp,int k){
        int s=0;
        int e=temp.size()-1;
        int ans=-1;
        while(s<=e){
            int mid= e+(s-e)/2;
            if(temp[mid]==k) return mid;
            else if(temp[mid]>k){
                ans=mid;
                e=mid-1;
            }else s=mid+1;
        }
        return ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()) temp.push_back(nums[i]);
            else{
                int lb =lowerbound(temp,nums[i]);
                temp[lb]=nums[i];
            }
        }
        return temp.size();
    }
};