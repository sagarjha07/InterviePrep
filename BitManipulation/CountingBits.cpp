// LEETCODE 338

class Solution {
public:
    vector<int> countBits(int n) {
        if(n==0) return {0};
        vector<int> ans(n+1,0);
        ans[0]=0;
        for(int i=1;i<=n;i++){
            //odd case
            if(i&1){
                ans[i]=ans[i-1]+1;
            } 
            // even case
            else ans[i]=ans[i/2];
        }
        return ans;
    }
};