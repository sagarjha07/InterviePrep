// LEETCODE 931

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                int temp=INT_MAX;
                if(j-1>=0) temp=min(temp,arr[i+1][j-1]);
                if(j+1<m) temp=min(temp,arr[i+1][j+1]);
                temp=min(temp,arr[i+1][j]);
                arr[i][j]+=temp;
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<m;i++){
            ans=min(ans,arr[0][i]);
        }
        return ans;
    }
};
