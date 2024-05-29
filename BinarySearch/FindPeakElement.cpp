//LEETCODE 162

class Solution {
public:
    int findPeakElement(vector<int>& a) {
        if(a.size()==1) return 0;
        int s=1;
        int e=a.size()-2;
        while(s<=e){
            int mid = (s+e)/2;
            if(a[mid]>a[mid+1] && a[mid]>a[mid-1]) return mid;
            else if(a[mid]<a[mid+1]) s=mid+1;
            else e=mid-1;
        }
        if(a[0]>a[1]) return 0;
        if(a[a.size()-2]<a[a.size()-1]) return a.size()-1;
        return -1;
    }
};
