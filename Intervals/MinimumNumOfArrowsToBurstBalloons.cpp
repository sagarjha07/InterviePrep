// LEETCODE 452
//same as non-overlapping intervals 
//just return n-ans; since ans=minimum no. of intervals deletion to make array non-overlapping
//handle equal to case also

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int last=arr[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(arr[i][0]>last){
                last=arr[i][1];
            } else{
                count+=1;
                last=min(arr[i][1],last);
            }
        }
        return n-count;
    }
};