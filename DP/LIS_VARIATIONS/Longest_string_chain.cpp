// LEETCODE 1048

class Solution {
public:
    static bool compare(string a,string b){
        return a.size()<b.size();
    }
    bool isValid(string a, string b){
        if(a.size()>b.size()){
            string c=a;
            a=b;
            b=c;
        }
        if(a.size()==b.size()) return false;
        if(b.size()!=a.size()+1) return false;
        int count=0;
        int i=0;
        int j=0;
        while(j<b.size()){
            if(i<a.size() && a[i]==b[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        if(i==a.size() && j==b.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),compare);
        int n=words.size();
        vector<int> dp(n,1);
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(isValid(words[j],words[i])){
                    dp[i]=max(dp[i],dp[j]+1);
                    
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};