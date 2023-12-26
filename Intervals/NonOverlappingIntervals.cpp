// LEETCODE 435

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int last=arr[0][1];
        int count=0;
        for(int i=1;i<n;i++){
            if(arr[i][0]>=last){
                last=arr[i][1];
            } else{
                //when not overlapping try to delete that interval which has higher end point
                // Greedily approach
                count+=1;
                last=min(arr[i][1],last);
            }
        }
        return count;
    }
};