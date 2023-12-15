// LEETCODE 1671
/*
You may recall that an array arr is a mountain array if and only if:

-arr.length >= 3
-There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
-----arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
-----arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.
*/

class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n=arr.size();
            int lis[n];
            lis[0]=1;
            for(int i=1;i<n;i++){
                lis[i]=1;
                for(int j=0;j<i;j++){
                    if(arr[i]>arr[j]){
                        lis[i]=max(lis[i],lis[j]+1);
                    }
                }
            }
            int lds[n];
            lds[n-1]=1;
            for(int i=n-2;i>=0;i--){
                lds[i]=1;
                for(int j=n-1;j>i;j--){
                    if(arr[j]<arr[i]){
                        lds[i]=max(lds[i],lds[j]+1);
                    }
                }
            }
            int ans=0;
            //consider middle point as strictly increasing or decreasing sequence will not be considered as mountain array
            for(int i=1;i<n-1;i++){
                if(lis[i]>1 && lds[i]>1) {
                    ans=max(ans,lis[i]+lds[i]-1);
                }
            }
        return arr.size()-ans;
    }
};