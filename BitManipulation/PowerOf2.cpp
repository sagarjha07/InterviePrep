// LEETCODE 231

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int count=0;
        while(n>0){
            if(n&1) count++;
            n=n>>1;
        }
        return count==1;
    }
};
