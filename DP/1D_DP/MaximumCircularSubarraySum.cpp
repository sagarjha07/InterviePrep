// LEETCODE 918

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0, maxSum = INT_MIN, curMax = 0, minSum = INT_MAX,
            curMin = 0;
        for (int x : nums) {
            curMax = max(x, curMax + x);
            maxSum = max(maxSum, curMax);
            curMin = min(x, curMin + x);
            minSum = min(minSum, curMin);
            totalSum += x;
        }
        if (maxSum < 0)
            return maxSum;
        return max(maxSum, totalSum - minSum);
    }
};