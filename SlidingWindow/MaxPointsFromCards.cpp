// LEETCODE 1423
// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
//Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> left(n+1,0);
        vector<int> right(n+1,0);
        for(int i=1;i<n+1;i++) left[i]=left[i-1]+arr[i-1];
        for(int i=n-1;i>=0;i--) right[i]=right[i+1]+arr[i];
        int ans=0;
        reverse(right.begin(),right.end());
        for(int i=0;i<=k;i++){
            ans=max({ans,left[i]+right[k-i]});
        }
        return ans;
    }
};
