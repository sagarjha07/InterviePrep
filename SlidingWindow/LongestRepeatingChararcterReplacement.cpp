// LEETCODE 424

class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans=-1;
        unordered_map<char,int> mp;
        int j=0;
        int i=0;
        int maxf=0;
        while(j<s.size()){
            mp[s[j]]+=1;
            maxf=max(maxf,mp[s[j]]);
            if(j-i+1-maxf<=k){
                ans=max(ans,j-i+1);
                j++;
            } else{
                mp[s[i]]-=1;
                i++;
                j++;
            }
        }
        return ans;
    }
};