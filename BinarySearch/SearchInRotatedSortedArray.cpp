// LEETCODE 33

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int s=0;
        int e=n-1;
         while(s<=e){
            int mid=(s+e)/2;
            if(arr[mid]==target) return mid;
            else if(arr[mid]>=arr[s]){
                if(target<arr[mid] && target>=arr[s]) e=mid-1;
                else s=mid+1;
            }
            else if(arr[mid]<=arr[e]){
                if(arr[mid]<target && target<=arr[e]) s=mid+1;
                else e=mid-1;
            }
        }
        return -1;
    }
};