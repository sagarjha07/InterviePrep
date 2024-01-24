// LEETCODE 48 Rotate Image 

class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=i;j<m;j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
        int i=0;
        int j=m-1;
        while(i<j){
            for(int k=0;k<n;k++){
                swap(arr[k][i],arr[k][j]);
            }
            i++;
            j--;
        }
    }
};
