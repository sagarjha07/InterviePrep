// LEETCODE 11

class Solution {
public:
    int maxArea(vector<int>& a) {
        int ans=0;
        int i=0;
        int j=a.size()-1;
        while(i<j){
            int mn=min(a[i],a[j]);
            ans=max(ans,mn*(j-i));
            if(a[i]==mn) i++;
            else j--;
        }
        return ans;
    }
};