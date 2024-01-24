// LEETCODE 42
//LMAX AND RMAX Space Complexity O(N)
class Solution {
public:
    int trap(vector<int>& heights) {
        int n=heights.size();
        vector<int> lmax(n,0);
        vector<int> rmax(n,0);
        lmax[0]=heights[0];
        rmax[n-1]=heights[n-1];
        for(int i=1;i<n;i++){
            lmax[i]=max(lmax[i-1],heights[i]);
        }
        for(int i=n-2;i>=0;i--){
            rmax[i]=max(rmax[i+1],heights[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(lmax[i],rmax[i])-heights[i];
        }
        return ans;
    }
};


//Two pointers approach Space Complexity O(1)
class Solution {
public:
    int trap(vector<int>& heights) {
        int n=heights.size();
        int ans=0;
        int lmax=0;
        int rmax=0;
        int i=0;
        int j=n-1;
        while(i<j){
            if(heights[i]<heights[j]){
                lmax=max(lmax,heights[i]);
                ans+=(lmax-heights[i]);
                i++;
            } else {
                rmax=max(rmax,heights[j]);
                ans+=(rmax-heights[j]);
                j--;
            }
        }
        return ans;
    }
};