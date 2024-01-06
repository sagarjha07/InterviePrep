// LEETCODE 73

class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        bool fr=false;
        bool fc=false;
        for(int i=0;i<n;i++){
            if(arr[i][0]==0) fc=true;
        }
        for(int i=0;i<m;i++){
            if(arr[0][i]==0) fr=true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[i][j]==0){
                    arr[i][0]=0;
                    arr[0][j]=0;
                }
            }
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[i][0]==0 || arr[0][j]==0) arr[i][j]=0;
            }
        }
        if(fr) {
            for(int i=0;i<m;i++) arr[0][i]=0;
        }
        if(fc){
            for(int i=0;i<n;i++) arr[i][0]=0;
        }
    }
};