// LEETCODE 120
// Start from bottom and do the changes in-place
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==0) return 0;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                triangle[i][j]=min(triangle[i+1][j],triangle[i+1][j+1])+triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};