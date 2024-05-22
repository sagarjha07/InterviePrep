// LEETCODE 135

// There are n children standing in a line.
// Each child is assigned a rating value given in the integer array ratings.
// You are giving candies to these children subjected to the following requirements:
// Each child must have at least one candy.
//Children with a higher rating get more candies than their neighbors.
//Return the minimum number of candies you need to have to distribute the candies to the children.

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int> arr(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i-1]<ratings[i]) arr[i]=arr[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i+1]<ratings[i] && arr[i]<=arr[i+1]) arr[i]=arr[i+1]+1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=arr[i];
        }
        return ans;
    }
};
