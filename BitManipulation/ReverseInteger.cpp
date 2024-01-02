// LEETCODE 7

class Solution {
public:
    int reverse(int x) {
        bool flag = false;
        if (x < 0)
            flag = true;
        long long ans = 0;
        int y = abs(x);
        while (y > 0) {
            ans = ans * 10 + y % 10;
            y = y / 10;
        }
        if (flag)
            ans = -1 * ans;
        return ans < INT_MIN || ans > INT_MAX ? 0 : ans;
    }
};