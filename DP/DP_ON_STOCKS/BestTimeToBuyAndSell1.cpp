//LEETCODE 121

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minSoFar=INT_MAX;
        int ans=0;
        for(int i=0;i<prices.size();i++){
            minSoFar=min(minSoFar,prices[i]);
            ans=max(ans,prices[i]-minSoFar);
        }
        return ans;
    }
};