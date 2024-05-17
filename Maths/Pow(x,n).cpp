// LEETCODE 50

class Solution {
public:
    double myPow(double x, int n) {
        double res=1;
        bool flag=false;
        if(n==INT_MIN && x!=1.0 && x!=-1.0) return 0;
        if(n<0){
            flag=true;
            n=0ll-n;
        }
        while(n>0){
            if(n&1){
                res=res*x;
            }
            x=x*x;
            n=n>>1;
        }
        if(flag) return 1/res;
        return res;
    }
};