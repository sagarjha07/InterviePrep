//SPACE OPTIMISED DP
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
    int a=text1.size();
    int b=text2.size();
    int dp[a+1][b+1];
    for(int i=0;i<a+1;i++) dp[i][0]=0;
    for(int i=0;i<b+1;i++) dp[0][i]=0;
    for(int i=1;i<a+1;i++){
        for(int j=1;j<b+1;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];;
            }
            else {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[a][b];
    }
};