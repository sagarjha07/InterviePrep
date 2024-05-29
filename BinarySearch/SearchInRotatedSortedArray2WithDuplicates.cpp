// LEETCODE 81

class Solution {
public:
    bool search(vector<int>& a, int target) {
        int s=0;
        int e=a.size()-1;
        // to handle duplicates
        while(s<e && a[s]==a[e]){
            s++;
        }
        while(s<=e){
            int mid=(s+e)/2;
            if(a[mid]==target) return true;
            else if(a[mid]>=a[s]){
                if(a[mid]>=target && target>=a[s]){
                    e=mid-1;
                }
                else s=mid+1;
            }
            else{
                if(a[mid]<=target && target<=a[e]){
                    s=mid+1;
                }
                else e=mid-1;
            }
            
        }
        return false;
    }
};
