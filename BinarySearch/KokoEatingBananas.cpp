// LEETCODE 875

class Solution {
public:
    bool isValid(vector<int>&arr,int h, int m){
        long long ans=0;
        for(int i=0;i<arr.size();i++){
            ans+=(long long)ceil((double)arr[i]/m);
        }
        return ans<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int mx=-1;
        for(int i=0;i<n;i++) {
            mx=max(mx,piles[i]);
        }
        int s=1;
        int e=mx;
        int ans=-1;
        while(s<=e){
            int m=(s+e)/2;
            if(isValid(piles,h,m)){
                ans=m;
                e=m-1;
            } else s=m+1;
        }
        return ans;
    }
};