// LEETCODE 647

class Solution {
public:
    int expandFromCenter(string &s, int i, int j){
        int ans=0;
        int n=s.size();
        while(i>=0 && j<n){
            if(s[i]!=s[j]) break;
            ans+=1;
            i--;
            j++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=expandFromCenter(s,i,i);
            ans+=expandFromCenter(s,i,i+1);
        }
        return ans;
    }
};