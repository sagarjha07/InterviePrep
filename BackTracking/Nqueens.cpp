// LEETCODE 51

class Solution {
public:
    bool canplace(vector<string>&board,int i,int j,int n){
        for(int r=0;r<=i;r++){
            if(board[r][j]=='Q') return false;
        }
        for(int c=0;c<=j;c++){
            if(board[i][c]=='Q') return false;
        }
        int r=i;
        int c=j;
        while(r>=0 && c>=0){
            if(board[r][c]=='Q') return false;
            r--;
            c--;
        }
        r=i;
        c=j;
        while(r>=0 && c<n){
            if(board[r][c]=='Q') return false;
            r--;
            c++;
        }
        return true;
    }
    bool solve(int i,int n,vector<string> board,vector<vector<string>>&ans){
        if(i==n){
            ans.push_back(board);
            return false;
        }
        for(int j=0;j<n;j++){
            if(canplace(board,i,j,n)){
                board[i][j]='Q';
                bool ansMila=solve(i+1,n,board,ans);
                if(ansMila) return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        solve(0,n,board,ans);
        return ans;
    }
};