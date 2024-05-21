// LEETCODE 260
// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. 
//Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

class Solution {
public:
    vector<int> singleNumber(vector<int>& a) {
        int n=a.size();
        vector<int> ans;
        int x = 0;
        for(int i=0;i<n;i++) x^=a[i];
        int y=0;
        //find index of rightMost set bit in xor of these two elements
        for(int i=0;i<32;i++){
            if((x>>i)&1) {
                y=i;
                break;
            }
        }
        int num1=0;
        for(int i=0;i<n;i++){
            if((a[i]>>y)&1) num1^=a[i];
        }
        int num2=x^num1;
        ans.push_back(num1);
        ans.push_back(num2);
        return ans;
    }
};
