// LEETCODE 2220

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        for(int i=31;i>=0;i--){
            int x=start>>i &1;
            int y=goal>>i &1;
            if(x!=y) ans+=1;
        }
        return ans;
    }
};
