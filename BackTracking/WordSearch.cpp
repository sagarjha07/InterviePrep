// LEETCODE 79

class Solution {
public:
    bool solve(int i,int j,int n,int m,vector<vector<char>>& arr,string word,int k){
        if(k==word.size()) return true;
        if(i>=n || i<0 || j>=m || j<0 || word[k]!=arr[i][j]) return false;
        arr[i][j]='#';
        bool op1=solve(i+1,j,n,m,arr,word,k+1);
        bool op2=solve(i-1,j,n,m,arr,word,k+1);
        bool op3=solve(i,j+1,n,m,arr,word,k+1);
        bool op4=solve(i,j-1,n,m,arr,word,k+1);
        arr[i][j]=word[k];
        return op1 || op2 || op3 || op4;
    }
    bool exist(vector<vector<char>>& arr, string word) {
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==word[0]){
                    bool ans = solve(i,j,n,m,arr,word,0);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
};